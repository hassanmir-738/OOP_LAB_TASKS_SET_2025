#include "Motorbike.h"

Motorbike::Motorbike(int id, const std::string& makeModel, double dailyRate, int engineCC)
    : Vehicle(id, makeModel, dailyRate),
      ccEngine(engineCC)
{}

int Motorbike::getEngineCC() const
{
    return ccEngine;
}

// Rentals of 7 days or fewer: standard rate.
// Rentals of 8 days or more: 10 % discount applied to the total.
double Motorbike::calculateCost(int days) const
{
    double total = getDailyRate() * days;

    const int    LONG_STAY_THRESHOLD = 7;
    const double DISCOUNT_RATE       = 0.90;

    if (days > LONG_STAY_THRESHOLD)
        total *= DISCOUNT_RATE;

    return total;
}

std::string Motorbike::typeName() const
{
    return "Motorbike";
}

std::string Motorbike::specification() const
{
    return std::to_string(ccEngine) + " cc engine";
}
