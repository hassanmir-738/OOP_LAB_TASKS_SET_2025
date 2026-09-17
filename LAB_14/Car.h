#ifndef CAR_H
#define CAR_H

#include <string>
#include "Vehicle.h"

/*
 * Car — a Vehicle priced at the base daily rate with no adjustment.
 * The only Car-specific attribute is the number of passenger seats.
 */
class Car : public Vehicle
{
private:
    int numSeats;

public:
    Car(int id, const std::string& makeModel, double dailyRate, int seats);

    int getSeats() const;

    double      calculateCost (int days) const override;
    std::string typeName      ()         const override;
    std::string specification ()         const override;
};

#endif
