#include "RentalSystem.h"

#include <iomanip>
#include <iostream>
#include <sstream>

// file-local helper: formats a monetary value with a $ sign and two decimal places
static std::string formatMoney(double amount)
{
    std::ostringstream ss;
    ss << "$" << std::fixed << std::setprecision(2) << amount;
    return ss.str();
}

RentalSystem::RentalSystem() : nextId(1) {}

// ---------------------------------------------------------------------------
// Lookup helpers
// ---------------------------------------------------------------------------

Vehicle* RentalSystem::findVehicle(int vehicleId)
{
    for (std::size_t i = 0; i < fleet.size(); ++i)
    {
        if (fleet[i]->getId() == vehicleId)
            return fleet[i].get();
    }
    return nullptr;
}

const Vehicle* RentalSystem::findVehicle(int vehicleId) const
{
    for (std::size_t i = 0; i < fleet.size(); ++i)
    {
        if (fleet[i]->getId() == vehicleId)
            return fleet[i].get();
    }
    return nullptr;
}

Customer* RentalSystem::findCustomer(int customerId)
{
    for (std::size_t i = 0; i < customers.size(); ++i)
    {
        if (customers[i].getId() == customerId)
            return &customers[i];
    }
    return nullptr;
}

const Customer* RentalSystem::findCustomer(int customerId) const
{
    for (std::size_t i = 0; i < customers.size(); ++i)
    {
        if (customers[i].getId() == customerId)
            return &customers[i];
    }
    return nullptr;
}

Rental* RentalSystem::findActiveRentalForVehicle(int vehicleId)
{
    for (std::size_t i = 0; i < rentals.size(); ++i)
    {
        if (rentals[i].getVehicleId() == vehicleId && rentals[i].isActive())
            return &rentals[i];
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// Fleet and customer setup
// ---------------------------------------------------------------------------

bool RentalSystem::addVehicle(std::unique_ptr<Vehicle> vehicle)
{
    if (vehicle == nullptr)
    {
        std::cout << "  REJECTED: cannot add a null vehicle.\n";
        return false;
    }

    if (findVehicle(vehicle->getId()) != nullptr)
    {
        std::cout << "  REJECTED: vehicle id " << vehicle->getId()
                  << " is already registered in the fleet.\n";
        return false;
    }

    std::cout << "  Added " << vehicle->typeName()
              << ": "       << vehicle->getMakeModel()
              << " (id "    << vehicle->getId()
              << ", "       << vehicle->specification()
              << ", "       << formatMoney(vehicle->getDailyRate())
              << " per day)\n";

    fleet.push_back(std::move(vehicle));
    return true;
}

bool RentalSystem::registerCustomer(int customerId, const std::string& name)
{
    if (findCustomer(customerId) != nullptr)
    {
        std::cout << "  REJECTED: customer id " << customerId
                  << " is already on record.\n";
        return false;
    }

    customers.push_back(Customer(customerId, name));
    std::cout << "  Registered: " << name << " (id " << customerId << ")\n";
    return true;
}

// ---------------------------------------------------------------------------
// Core operations
// ---------------------------------------------------------------------------

bool RentalSystem::rentVehicle(int customerId, int vehicleId, int days)
{
    if (days <= 0)
    {
        std::cout << "  REJECTED: rental must be at least 1 day"
                  << " (requested: " << days << ").\n";
        return false;
    }

    Customer* cust = findCustomer(customerId);
    if (cust == nullptr)
    {
        std::cout << "  REJECTED: no customer with id " << customerId << ".\n";
        return false;
    }

    Vehicle* veh = findVehicle(vehicleId);
    if (veh == nullptr)
    {
        std::cout << "  REJECTED: no vehicle with id " << vehicleId << ".\n";
        return false;
    }

    if (cust->hasActiveRental())
    {
        std::cout << "  REJECTED: " << cust->getName()
                  << " already has an open rental (one at a time only).\n";
        return false;
    }

    if (!veh->isAvailable())
    {
        std::cout << "  REJECTED: " << veh->getMakeModel()
                  << " is currently rented out.\n";
        return false;
    }

    // Virtual dispatch: the correct pricing override runs here
    // (Car plain rate / Motorbike discount / Truck surcharge).
    double cost = veh->calculateCost(days);

    rentals.push_back(Rental(nextId, customerId, vehicleId, days, cost));
    nextId++;

    veh->markAsRented();
    cust->startRental();

    std::cout << "  OK: rental #" << rentals.back().getRentalId()
              << " — "            << cust->getName()
              << " rents "        << veh->getMakeModel()
              << " ("             << veh->typeName()
              << ") for "         << days << " day(s)."
              << " Total: "       << formatMoney(cost) << "\n";
    return true;
}

bool RentalSystem::returnVehicle(int vehicleId)
{
    Vehicle* veh = findVehicle(vehicleId);
    if (veh == nullptr)
    {
        std::cout << "  REJECTED: no vehicle with id " << vehicleId << ".\n";
        return false;
    }

    Rental* rec = findActiveRentalForVehicle(vehicleId);
    if (rec == nullptr)
    {
        std::cout << "  REJECTED: " << veh->getMakeModel()
                  << " is not currently rented out.\n";
        return false;
    }

    rec->close();
    veh->markAsReturned();

    Customer* cust = findCustomer(rec->getCustomerId());
    if (cust != nullptr)
        cust->endRental();

    std::cout << "  OK: " << veh->getMakeModel()
              << " returned. Rental #" << rec->getRentalId() << " is closed";
    if (cust != nullptr)
        std::cout << " and " << cust->getName() << " may rent again";
    std::cout << ".\n";

    return true;
}

// ---------------------------------------------------------------------------
// Reporting
// ---------------------------------------------------------------------------

void RentalSystem::printActiveRentals() const
{
    std::cout << "\n--- ACTIVE RENTALS ---\n";

    int count = 0;
    for (std::size_t i = 0; i < rentals.size(); ++i)
        if (rentals[i].isActive()) ++count;

    if (count == 0)
    {
        std::cout << "  (none)\n";
        return;
    }

    std::cout << "  " << std::left
              << std::setw(6)  << "No."
              << std::setw(20) << "Customer"
              << std::setw(22) << "Vehicle"
              << std::setw(12) << "Type"
              << std::setw(7)  << "Days"
              << "Cost\n";
    std::cout << "  " << std::string(76, '-') << "\n";

    for (std::size_t i = 0; i < rentals.size(); ++i)
    {
        const Rental& r = rentals[i];
        if (!r.isActive()) continue;

        const Customer* c = findCustomer(r.getCustomerId());
        const Vehicle*  v = findVehicle(r.getVehicleId());

        std::cout << "  " << std::left
                  << std::setw(6)  << ("#" + std::to_string(r.getRentalId()))
                  << std::setw(20) << (c != nullptr ? c->getName()      : "<unknown>")
                  << std::setw(22) << (v != nullptr ? v->getMakeModel() : "<unknown>")
                  << std::setw(12) << (v != nullptr ? v->typeName()     : "-")
                  << std::setw(7)  << r.getDays()
                  << formatMoney(r.getTotalCost()) << "\n";
    }
}

void RentalSystem::printRentalHistory() const
{
    std::cout << "\n--- RENTAL HISTORY (all records, including closed) ---\n";

    if (rentals.empty())
    {
        std::cout << "  (none)\n";
        return;
    }

    std::cout << "  " << std::left
              << std::setw(6)  << "No."
              << std::setw(20) << "Customer"
              << std::setw(22) << "Vehicle"
              << std::setw(7)  << "Days"
              << std::setw(12) << "Cost"
              << "Status\n";
    std::cout << "  " << std::string(76, '-') << "\n";

    for (std::size_t i = 0; i < rentals.size(); ++i)
    {
        const Rental&   r = rentals[i];
        const Customer* c = findCustomer(r.getCustomerId());
        const Vehicle*  v = findVehicle(r.getVehicleId());

        std::cout << "  " << std::left
                  << std::setw(6)  << ("#" + std::to_string(r.getRentalId()))
                  << std::setw(20) << (c != nullptr ? c->getName()      : "<unknown>")
                  << std::setw(22) << (v != nullptr ? v->getMakeModel() : "<unknown>")
                  << std::setw(7)  << r.getDays()
                  << std::setw(12) << formatMoney(r.getTotalCost())
                  << (r.isActive() ? "ACTIVE" : "CLOSED") << "\n";
    }
}

void RentalSystem::printFleetAvailability() const
{
    std::cout << "\n--- FLEET AVAILABILITY ---\n";

    int avail = 0, out = 0;
    for (std::size_t i = 0; i < fleet.size(); ++i)
        fleet[i]->isAvailable() ? ++avail : ++out;

    std::cout << "  Available : " << avail        << "\n";
    std::cout << "  Rented out: " << out           << "\n";
    std::cout << "  Total     : " << fleet.size()  << "\n";

    if (fleet.empty()) return;

    std::cout << "\n  " << std::left
              << std::setw(6)  << "Id"
              << std::setw(22) << "Vehicle"
              << std::setw(12) << "Type"
              << std::setw(20) << "Specification"
              << std::setw(11) << "Rate/day"
              << "Status\n";
    std::cout << "  " << std::string(76, '-') << "\n";

    for (std::size_t i = 0; i < fleet.size(); ++i)
    {
        const Vehicle& v = *fleet[i];
        std::cout << "  " << std::left
                  << std::setw(6)  << v.getId()
                  << std::setw(22) << v.getMakeModel()
                  << std::setw(12) << v.typeName()
                  << std::setw(20) << v.specification()
                  << std::setw(11) << formatMoney(v.getDailyRate())
                  << (v.isAvailable() ? "Available" : "Rented out") << "\n";
    }
}

void RentalSystem::printSummary() const
{
    std::cout << "\n============================ SUMMARY ============================\n";
    printActiveRentals();
    printRentalHistory();
    printFleetAvailability();
    std::cout << "=================================================================\n";
}
