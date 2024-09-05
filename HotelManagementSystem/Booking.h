/* 
* Description:
* Privare members: 
* bookedRoom: An object of the Room class representing the booked room.
* bookingCustomer: An object of the Customer class representing the customer who made the booking.
* Public members: 
* Constructor to create a booking with a specified room and customer.
* Getters: Methods to access the booked room and booking customer.
*/

#ifndef BOOKING_H
#define BOOKING_H

#include "Room.h"
#include "Customer.h"      

using namespace std;

// Booking class declaration
class Booking {
private:
    // Private member variables representing the booked room and booking customer.
    Room bookedRoom;
    Customer bookingCustomer;

public:
    // Parameterized constructor for the Booking class.
    Booking(const Room& room, const Customer& customer);

    // Getter method for retrieving the booked room.
    const Room& getBookedRoom() const;

    // Getter method for retrieving the booking customer.
    const Customer& getBookingCustomer() const;

};

#endif
