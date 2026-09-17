#include "Customer.h"

Customer::Customer(int id, const std::string& name)
    : custId(id),
      fullName(name),
      rentalOpen(false)
{
    // fresh customer — no rental is open yet
}

int Customer::getId() const
{
    return custId;
}

const std::string& Customer::getName() const
{
    return fullName;
}

bool Customer::hasActiveRental() const
{
    return rentalOpen;
}

void Customer::startRental()
{
    rentalOpen = true;
}

void Customer::endRental()
{
    rentalOpen = false;
}
