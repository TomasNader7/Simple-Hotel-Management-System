/*
* Description: Initializes the hotel with a specified number of rooms, including single, double, and suite rooms.
* Implements methods to show available rooms, book/unbook rooms, and display booked rooms. Uses the Room and Booking classes for these operations.
*/
#include "Hotel.h"
#include "Room.h"
#include "Booking.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> // for find_if

using namespace std;

// Constructor for the Hotel class.
// Initializes the hotel with a specified number of single, double, and suite rooms.
Hotel::Hotel(int numSingleRooms, int numDoubleRooms, int numSuites) {
    for (int i = 1; i <= numSingleRooms; ++i) {
        rooms.push_back(Room(i, "Single", 50.0, 2, false));
    }

    for (int i = numSingleRooms + 1; i <= numSingleRooms + numDoubleRooms; ++i) {
        rooms.push_back(Room(i, "Double", 100.0, 4, false));
    }

    for (int i = numSingleRooms + numDoubleRooms + 1; i <= numSingleRooms + numDoubleRooms + numSuites; ++i) {
        rooms.push_back(Room(i, "Suite", 200.0, 8, true));
    }
}

// Display information about available rooms.
void Hotel::roomsAvailable() const {
    cout << "Available Rooms:" << endl;
    for (const auto& room : rooms) {
        room.displayInfo();
        cout << "Price $" << room.getPrice() << " per night." << endl;
        cout << endl;
    }
}

// Book a room for a customer.
// Returns a reference to the booked room.
const Room& Hotel::bookRoom(int roomNumber, const Customer& customer) {
    auto it = find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
        return room.getRoomNumber() == roomNumber;
        });

    if (it != rooms.end()) {
        Room& room = *it;
        if (!room.isRoomBooked()) {
            room.bookRoom();
            Booking newBooking(room, customer);
            bookings.push_back(newBooking);
            cout << "Room " << roomNumber << " booked by " << customer.getName() << "." << endl;
            return room;  // Return a reference to the booked room
        }
        else {
            cout << "Error. Room " << roomNumber << " is already booked." << endl;
            // Throw an exception or handle the error as needed
        }
    }
    else {
        cout << "Error. Room " << roomNumber << " not found or not available for booking." << endl;
        // Throw an exception or handle the error as needed
    }

    // Handle the case when an error occurs (e.g., throw an exception)
    throw runtime_error("Error occurred while booking the room.");
}

// Unbook a room based on its room number.
void Hotel::unbookRoom(int roomNumber) {
    auto it = find_if(bookings.begin(), bookings.end(), [roomNumber](const Booking& booking) {
        return booking.getBookedRoom().getRoomNumber() == roomNumber;
        });

    if (it != bookings.end()) {
        Room& bookedRoom = const_cast<Room&>(it->getBookedRoom());
        bookedRoom.unbookRoom();
        bookings.erase(it);
        cout << "Room " << roomNumber << " unbooked successfully." << endl;
    }
    else {
        cout << "Error. Room " << roomNumber << " not found in bookings." << endl;
    }
}

// Retrieve a vector of all bookings made in the hotel.
const vector<Booking>& Hotel::getBookings() const {
    return bookings;
}

// Display information about all booked rooms and their corresponding customers.
void Hotel::roomsBooked() const {
    for (const auto& booking : bookings) {
        const Room& room = booking.getBookedRoom();
        room.displayInfo();
        cout << "Booked by: " << booking.getBookingCustomer().getName() << endl << endl;
    }
}

// Display a summary of guest information for a given customer.
void Hotel::guestSummary(const Customer& customer) const {
    cout << "Guest Summary:" << endl;
    cout << "Customer Name: " << customer.getName() << endl;
    cout << "Customer Age: " << customer.getAge() << endl;
    cout << "Customer Phone Number: " << customer.getPhoneNumber() << endl;
    cout << "Customer Address: " << customer.getAddress() << endl;

    // Format the booking date
    int bookingDate = customer.getBookingDate();
    int year = bookingDate % 10000;
    int month = (bookingDate / 10000) % 100;
    int day = bookingDate / 1000000;

    cout << "Booking Date: " << setfill('0') << setw(2) << month << '/' << setw(2) << day << '/' << year << endl;
    cout << "-------------------------" << endl;

}