#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

/*
 * Vehicle — abstract base for all rental fleet entries.
 *
 * Because the price calculation differs across vehicle types
 * (cars use plain rate, motorbikes offer long-stay discounts,
 * trucks carry a surcharge), calculateCost() is declared pure
 * virtual here, making this class non-instantiable on its own.
 */
class Vehicle
{
private:
    int         vehicleId;
    std::string model;
    double      ratePerDay;
    bool        rentedOut;

protected:
    Vehicle(int id, const std::string& model, double ratePerDay);

public:
    virtual ~Vehicle();

    // --- accessors ---
    int                getId()        const;
    const std::string& getMakeModel() const;
    double             getDailyRate() const;
    bool               isAvailable()  const;

    // --- state changers ---
    void markAsRented();
    void markAsReturned();

    // --- pure-virtual interface ---
    virtual double      calculateCost  (int days) const = 0;
    virtual std::string typeName       ()         const = 0;
    virtual std::string specification  ()         const = 0;
};

#endif
