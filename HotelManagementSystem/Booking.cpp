/*
* Description: Implements the methods declared in Booking.h. Initializes the booked room and customer using a parameterized constructor.
* Provides access to booked room and customer information.
*/
#include "Booking.h"

using namespace std;

// Parameterized constructor for the Booking class.
Booking::Booking(const Room& room, const Customer& customer)
    : bookedRoom(room), bookingCustomer(customer) {}

// Getter method to retrieve the information needed.
const Room& Booking::getBookedRoom() const {
    return bookedRoom;
}

const Customer& Booking::getBookingCustomer() const {
    return bookingCustomer;
}