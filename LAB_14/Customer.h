#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

/*
 * Customer — represents a person registered with the rental company.
 *
 * Business rule: a customer may hold at most one active rental at any
 * given time.  The flag below is toggled by RentalSystem whenever a
 * rental is opened or closed for that customer.
 */
class Customer
{
private:
    int         custId;
    std::string fullName;
    bool        rentalOpen;

public:
    Customer(int id, const std::string& name);

    int                getId()           const;
    const std::string& getName()         const;
    bool               hasActiveRental() const;

    void startRental();
    void endRental();
};

#endif
