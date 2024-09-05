/*
* Description: The Room.h file contains the declaration of the Room class, which represents individual rooms within the hotel management system.
* Furthermore, it contains getter and setter functions to perform different operations such as booking a room, or getting the room number.
* 
* Public members include the constructor, getter methods, and public member functions that provide information about the room or perform specific actions, such as booking or unbooking a room.
* Private members include the attributes specific to each room instance.
*/                                                                                         

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Room {
private:
    int roomNumber;                 // Unique identifier for the room
    int numberBeds;                 // Number of beds in the room
    double price_per_night;         // Price per night for the room
    string roomType;                // Type of the room (Single, Double, Suite)
    string amenities;               // Amenities available in the room
    bool isBooked;                  // Flag indicating whether the room is booked
    bool premiumRoom;               // Flag indicating whether the room is a premium room

public:
    Room(); // Default constructor

    Room(int p_roomNumber, const string& p_roomType, double p_price_per_night, int p_numberBeds, bool p_premiumRoom); // Parameterized constructor

    // Getter methods
    int getRoomNumber() const;
    const string& getRoomType() const;
    double getPrice() const;
    int getNumberBeds() const;
    const string& getAmenities() const;

    // Setter methods
    void setRoomNumber(int new_roomNumber);
    void setRoomType(const string& new_roomType);
    void setPrice(double new_price);
    void setNumberBeds(int new_numberBeds);
    void setAmenities();
    void setPremium(bool premium);
    bool isRoomBooked() const;

    // Method to display information about the room
    void displayInfo() const;

    // Methods to perform diffeerent operations within room class
    void bookRoom();
    void unbookRoom();
    bool PremiumRoom() const;
    void displayRoomType() const;
};

#endif
