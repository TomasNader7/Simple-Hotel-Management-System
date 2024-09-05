/*File: Prog4-Group6                                                                  Nader Tomas w10172066
* Assignment 4                                                                        Thales Teixeira Rodrigues w10173761
* 
* Description:
* 
* Private members:
* rooms: A vector of Room objects representing the rooms available in the hotel.
* bookings: A vector of Booking objects representing the rooms that are currently booked.
* Public members:
* Constructor to initialize the hotel with a specific number of single, double, and suite rooms.
* Methods to display/ perform different functions.
*/
#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include "Room.h"    
#include "Customer.h"
#include "Booking.h"

using namespace std;

enum class RoomType {
    Single,
    Double,
    Suite
};

class Hotel {
private:
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    // Constructor to initialize the hotel with a certain number of rooms
    Hotel(int numSingleRooms, int numDoubleRooms, int numSuites);

    // Function to show availables rooms 
    void roomsAvailable() const;

    // Functions to book and unbook rooms
    const Room& bookRoom(int roomNumber, const Customer& customer);
    void unbookRoom(int roomNumber);
    // New member function to get the bookings
    const vector<Booking>& getBookings() const;
    

    // Function to show rooms booked
    void roomsBooked() const; 

    // Function to show summary/report of customer, including charges, what was consumer in the room and personal info 
    void guestSummary(const Customer& customer) const;


};

#endif