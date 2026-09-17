#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Vehicle.h"

/*
 * Truck — a Vehicle with a mandatory 20 % surcharge on every rental.
 * The payload capacity (in metric tonnes) is stored as the type-specific detail.
 */
class Truck : public Vehicle
{
private:
    double cargoTonnes;

public:
    Truck(int id, const std::string& makeModel, double dailyRate, double payloadTonnes);

    double getPayloadTonnes() const;

    double      calculateCost (int days) const override;
    std::string typeName      ()         const override;
    std::string specification ()         const override;
};

#endif
