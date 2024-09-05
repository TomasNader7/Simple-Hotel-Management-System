/* 
* Description: Room.cpp contains the implementation of the methods declared in Room.h. 
* It defines how each method of the Room class behaves, including the constructor, setter and getter methods, and specific behaviors like booking and unbooking.
*/

#include "Room.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Default constructor
Room::Room() {
    roomNumber = 0;
    numberBeds = 0;
    price_per_night = 0.0;
    roomType = "";
    amenities = "";
    isBooked = false;
    premiumRoom = false;
}

// Parameterized constructor
Room::Room(int p_roomNumber, const string& p_roomType, double p_price_per_night, int p_numberBeds, bool p_premiumRoom)
    : roomNumber(p_roomNumber), roomType(p_roomType), price_per_night(p_price_per_night), numberBeds(p_numberBeds),
    isBooked(false), premiumRoom(p_premiumRoom) {
    // Ensure amenities are set when constructing the room
    setAmenities();
}

// Getter methods
int Room::getRoomNumber() const {
    return roomNumber;
}

const string& Room::getRoomType() const {
    return roomType;
}

double Room::getPrice() const {
    return price_per_night;
}

int Room::getNumberBeds() const {
    return numberBeds;
}

const string& Room::getAmenities() const {
    return amenities;
}

// Setter methods
void Room::setPremium(bool premium) {
    premiumRoom = premium;
}

void Room::setRoomNumber(int new_roomNumber) {
    roomNumber = new_roomNumber;
}

void Room::setRoomType(const string& new_roomType) {
    roomType = new_roomType;

    // Set price, number of beds, and premium status based on room type
    if (new_roomType == "Single") {
        setPrice(50.0);
        setNumberBeds(2);
        setPremium(false);
    }
    else if (new_roomType == "Double") {
        setPrice(100.0);
        setNumberBeds(4);
        setPremium(false);
    }
    else if (new_roomType == "Suite") {
        setPrice(200.0);
        setNumberBeds(8);
        setPremium(true);
    }
    else {
        cout << "Unknown room type. Please choose single, double, or suite" << endl;
    }

    // Update amenities based on the room type
    setAmenities();
}

void Room::setPrice(double new_price) {
    price_per_night = new_price;
}

void Room::setNumberBeds(int new_numberBeds) {
    numberBeds = new_numberBeds;
}

void Room::setAmenities() {
    // Define a map to store amenities for each room type
    unordered_map<string, string> amenitiesMap = {
        {"Single", "Wi-Fi, TV, AC"},
        {"Double", "Wi-Fi, TV, AC, Mini Fridge"},
        {"Suite", "Wi-Fi, Smart TV, AC, Mini Fridge, Jacuzzi, pool"}
    };

    // Update amenities based on the room type
    auto it = amenitiesMap.find(roomType);
    if (it != amenitiesMap.end()) {
        amenities = it->second;
    }
    else {
        cerr << "Unknown room type. Amenities not updated." << endl;
    }
}

// Other methods
bool Room::PremiumRoom() const {
    return premiumRoom;
}

bool Room::isRoomBooked() const {
    return isBooked;
}

void Room::bookRoom() {
    if (!isBooked) {
        isBooked = true;
        cout << "Room was booked successfully" << endl;
        cout << endl;
        
    }
    else {
        cout << "Error. Room is booked." << endl;
    }
}

void Room::unbookRoom() {
    if (isBooked) {
        isBooked = false;
        cout << "Room unbook successfully." << endl;
    }
    else {
        cout << "Error: Room is not booked." << endl;
    }
}

void Room::displayRoomType() const {
    if (PremiumRoom()) {
        cout << "You have selected the premium room." << endl;
    }
    else {
        cout << "You have selected a Regular room." << endl;
        cout << endl;
    }
    
}

void Room::displayInfo() const {
    cout << "Room number: " << getRoomNumber() << endl;
    cout << "Room type: " << getRoomType() << endl;
    cout << "Number of beds per room: " << getNumberBeds() << endl;
    cout << "Amenities: " << getAmenities() << endl;
    cout << "Premium Room: " << (PremiumRoom() ? "Yes" : "No") << endl;
}
