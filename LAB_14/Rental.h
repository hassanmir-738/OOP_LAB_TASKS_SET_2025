#ifndef RENTAL_H
#define RENTAL_H

/*
 * Rental — records a single transaction between one customer and one vehicle.
 *
 * Records are never deleted: closing a rental (when the vehicle comes back)
 * only flips the status flag so that the full history is always accessible.
 *
 * Customer and vehicle are referenced by integer IDs rather than pointers,
 * because the backing vectors may reallocate and invalidate stored pointers.
 *
 * The agreed price is captured when the rental is created and stored here,
 * so historical records are unaffected by future rate changes.
 */
class Rental
{
private:
    int    recId;
    int    custId;
    int    vehId;
    int    rentalDays;
    double agreedCost;
    bool   stillActive;

public:
    Rental(int rentalId, int customerId, int vehicleId, int days, double totalCost);

    int    getRentalId()   const;
    int    getCustomerId() const;
    int    getVehicleId()  const;
    int    getDays()       const;
    double getTotalCost()  const;
    bool   isActive()      const;

    // Marks the rental as closed; the record is kept for historical reference.
    void close();
};

#endif
