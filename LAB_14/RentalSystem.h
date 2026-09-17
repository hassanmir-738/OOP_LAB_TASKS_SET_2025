#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <memory>
#include <string>
#include <vector>

#include "Customer.h"
#include "Rental.h"
#include "Vehicle.h"

/*
 * RentalSystem — the central coordinator of the rental company.
 *
 * It owns the fleet, the customer registry, and the rental ledger.
 * All state transitions go through this class so the records stay
 * consistent with each other.
 *
 * Fleet vehicles are held via unique_ptr<Vehicle> so that Car,
 * Motorbike and Truck objects can coexist in one container and are
 * released automatically without any manual delete.
 * Customers and rentals are stored by value (no heap allocation needed).
 */
class RentalSystem
{
private:
    std::vector<std::unique_ptr<Vehicle> > fleet;
    std::vector<Customer>                  customers;
    std::vector<Rental>                    rentals;
    int                                    nextId;

    // --- internal lookup helpers ---
    Vehicle*       findVehicle              (int vehicleId);
    const Vehicle* findVehicle              (int vehicleId) const;
    Customer*      findCustomer             (int customerId);
    const Customer*findCustomer             (int customerId) const;
    Rental*        findActiveRentalForVehicle(int vehicleId);

public:
    RentalSystem();

    // --- fleet and customer setup ---
    bool addVehicle       (std::unique_ptr<Vehicle> vehicle);
    bool registerCustomer (int customerId, const std::string& name);

    // --- core operations ---
    bool rentVehicle   (int customerId, int vehicleId, int days);
    bool returnVehicle (int vehicleId);

    // --- reporting ---
    void printActiveRentals     () const;
    void printRentalHistory     () const;
    void printFleetAvailability () const;
    void printSummary           () const;
};

#endif
