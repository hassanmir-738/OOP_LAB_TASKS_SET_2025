#include "Car.h"

Car::Car(int id, const std::string& makeModel, double dailyRate, int seats)
    : Vehicle(id, makeModel, dailyRate),
      numSeats(seats)
{}

int Car::getSeats() const
{
    return numSeats;
}

// Cars are charged at the plain daily rate — no discount or surcharge applies.
double Car::calculateCost(int days) const
{
    return getDailyRate() * days;
}

std::string Car::typeName() const
{
    return "Car";
}

std::string Car::specification() const
{
    return std::to_string(numSeats) + " seats";
}