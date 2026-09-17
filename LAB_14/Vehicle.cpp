#include "Vehicle.h"

Vehicle::Vehicle(int id, const std::string& model, double ratePerDay)
    : vehicleId(id),
      model(model),
      ratePerDay(ratePerDay),
      rentedOut(false)
{
    // every vehicle enters the fleet ready to rent
}

// destructor definition ensures vtable is emitted in this translation unit
Vehicle::~Vehicle() {}

int Vehicle::getId() const
{
    return vehicleId;
}

const std::string& Vehicle::getMakeModel() const
{
    return model;
}

double Vehicle::getDailyRate() const
{
    return ratePerDay;
}

bool Vehicle::isAvailable() const
{
    return !rentedOut;
}

void Vehicle::markAsRented()
{
    rentedOut = true;
}

void Vehicle::markAsReturned()
{
    rentedOut = false;
}
