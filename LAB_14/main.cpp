// Lab 14 — Vehicle Rental System (Interactive / Open-Ended)
// OOP with C++ | Inheritance, Polymorphism, Encapsulation
//
// The program presents a numbered menu.  The user can:
//   1. Add a vehicle (choose Car / Motorbike / Truck and fill in the details)
//   2. Register a customer
//   3. Rent a vehicle
//   4. Return a vehicle
//   5. View active rentals
//   6. View rental history
//   7. View fleet availability
//   8. Exit

#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "Car.h"
#include "Motorbike.h"
#include "RentalSystem.h"
#include "Truck.h"

// ---------------------------------------------------------------------------
// Small helper utilities
// ---------------------------------------------------------------------------

// Print the main menu and return the user's choice.
static int showMenu()
{
    std::cout << "\n=========================================\n";
    std::cout << "     VEHICLE RENTAL SYSTEM — Menu\n";
    std::cout << "=========================================\n";
    std::cout << "  1. Add a vehicle to the fleet\n";
    std::cout << "  2. Register a customer\n";
    std::cout << "  3. Rent a vehicle\n";
    std::cout << "  4. Return a vehicle\n";
    std::cout << "  5. View active rentals\n";
    std::cout << "  6. View rental history\n";
    std::cout << "  7. View fleet availability\n";
    std::cout << "  0. Exit\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Enter your choice: ";

    int choice = 0;
    std::cin >> choice;

    // Recover from bad input (e.g. the user typed a letter).
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

// Read a non-empty string from stdin after printing a prompt.
static std::string readString(const std::string& prompt)
{
    std::string value;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        std::cout << "  (input cannot be empty, please try again)\n";
    }
}

// Read an integer from stdin after printing a prompt.
static int readInt(const std::string& prompt)
{
    int value = 0;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail())
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  (invalid input, please enter a whole number)\n";
    }
}

// Read a positive double from stdin after printing a prompt.
static double readPositiveDouble(const std::string& prompt)
{
    double value = 0.0;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail() && value > 0.0)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  (must be a positive number, please try again)\n";
    }
}

// ---------------------------------------------------------------------------
// Menu action handlers
// ---------------------------------------------------------------------------

static void handleAddVehicle(RentalSystem& company)
{
    std::cout << "\n--- Add a Vehicle ---\n";
    std::cout << "  Vehicle types:\n";
    std::cout << "    1. Car       (plain daily rate, no surcharge)\n";
    std::cout << "    2. Motorbike (10% discount for rentals > 7 days)\n";
    std::cout << "    3. Truck     (20% surcharge on every rental)\n";

    int typeChoice = readInt("  Select type (1/2/3): ");

    if (typeChoice < 1 || typeChoice > 3)
    {
        std::cout << "  Invalid vehicle type selected.\n";
        return;
    }

    int    vehicleId  = readInt   ("  Vehicle ID        : ");
    std::string model = readString("  Make & Model      : ");
    double rate       = readPositiveDouble("  Daily rate (PKR)  : ");

    if (typeChoice == 1)
    {
        // --- Car ---
        int seats = readInt("  Number of seats  : ");
        company.addVehicle(std::make_unique<Car>(vehicleId, model, rate, seats));
    }
    else if (typeChoice == 2)
    {
        // --- Motorbike ---
        int cc = readInt("  Engine size (cc)  : ");
        company.addVehicle(std::make_unique<Motorbike>(vehicleId, model, rate, cc));
    }
    else
    {
        // --- Truck ---
        double payload = readPositiveDouble("  Payload (tonnes)  : ");
        company.addVehicle(std::make_unique<Truck>(vehicleId, model, rate, payload));
    }
}

static void handleRegisterCustomer(RentalSystem& company)
{
    std::cout << "\n--- Register a Customer ---\n";
    int         custId = readInt   ("  Customer ID  : ");
    std::string name   = readString("  Full name    : ");
    company.registerCustomer(custId, name);
}

static void handleRentVehicle(RentalSystem& company)
{
    std::cout << "\n--- Rent a Vehicle ---\n";
    int custId    = readInt("  Customer ID : ");
    int vehicleId = readInt("  Vehicle ID  : ");
    int days      = readInt("  Number of days: ");
    company.rentVehicle(custId, vehicleId, days);
}

static void handleReturnVehicle(RentalSystem& company)
{
    std::cout << "\n--- Return a Vehicle ---\n";
    int vehicleId = readInt("  Vehicle ID  : ");
    company.returnVehicle(vehicleId);
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

int main()
{
    RentalSystem company;

    std::cout << "=========================================\n";
    std::cout << "     VEHICLE RENTAL SYSTEM — Lab 14\n";
    std::cout << "=========================================\n";
    std::cout << "  System started with an empty fleet.\n";
    std::cout << "  Use the menu to add vehicles and\n";
    std::cout << "  customers, then process rentals.\n";

    bool running = true;
    while (running)
    {
        int choice = showMenu();

        switch (choice)
        {
            case 1:
                handleAddVehicle(company);
                break;

            case 2:
                handleRegisterCustomer(company);
                break;

            case 3:
                handleRentVehicle(company);
                break;

            case 4:
                handleReturnVehicle(company);
                break;

            case 5:
                company.printActiveRentals();
                break;

            case 6:
                company.printRentalHistory();
                break;

            case 7:
                company.printFleetAvailability();
                break;

            case 0:
                std::cout << "\nThank you for using the Vehicle Rental System. Goodbye!\n";
                running = false;
                break;

            default:
                std::cout << "\n  Invalid option. Please enter a number from the menu.\n";
                break;
        }
    }

    return 0;
}
