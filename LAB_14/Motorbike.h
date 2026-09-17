#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>
#include "Vehicle.h"

/*
 * Motorbike — a Vehicle that rewards long rentals with a price reduction.
 * When the rental period exceeds 7 days the total is reduced by 10 %.
 * The engine displacement (in cc) is stored as the type-specific detail.
 */
class Motorbike : public Vehicle
{
private:
    int ccEngine;

public:
    Motorbike(int id, const std::string& makeModel, double dailyRate, int engineCC);

    int getEngineCC() const;

    double      calculateCost (int days) const override;
    std::string typeName      ()         const override;
    std::string specification ()         const override;
};

#endif
