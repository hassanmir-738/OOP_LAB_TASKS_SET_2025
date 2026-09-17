#include "Rental.h"

Rental::Rental(int rentalId, int customerId, int vehicleId, int days, double totalCost)
    : recId(rentalId),
      custId(customerId),
      vehId(vehicleId),
      rentalDays(days),
      agreedCost(totalCost),
      stillActive(true)
{
    // every new rental starts in the active state
}

int Rental::getRentalId() const
{
    return recId;
}

int Rental::getCustomerId() const
{
    return custId;
}

int Rental::getVehicleId() const
{
    return vehId;
}

int Rental::getDays() const
{
    return rentalDays;
}

double Rental::getTotalCost() const
{
    return agreedCost;
}

bool Rental::isActive() const
{
    return stillActive;
}

// The vehicle has been returned — close this record but keep it in history.
void Rental::close()
{
    stillActive = false;
}
