#include "Truck.h"
#include <iomanip>
#include <sstream>

Truck::Truck(int id, const std::string& makeModel, double dailyRate, double payloadTonnes)
    : Vehicle(id, makeModel, dailyRate),
      cargoTonnes(payloadTonnes)
{}

double Truck::getPayloadTonnes() const
{
    return cargoTonnes;
}

// All truck rentals are subject to a 20 % surcharge on the base price.
double Truck::calculateCost(int days) const
{
    const double SURCHARGE = 1.20;
    return getDailyRate() * days * SURCHARGE;
}

std::string Truck::typeName() const
{
    return "Truck";
}

std::string Truck::specification() const
{
    // Use a stream to keep one decimal place instead of six.
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(1) << cargoTonnes << " tonne payload";
    return ss.str();
}
