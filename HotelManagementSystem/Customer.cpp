/*
* Description: Implements the methods declared in Customer.h. Initializes customer attributes using the default and parameterized constructors.
*/
#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor definition.
Customer::Customer() {
    name = "";
    age = 0;
    phoneNumber = 0;
    address = "";
    bookingDate = 0;
}

// Parameterized constructor definition.
Customer::Customer(const string& p_name, int p_age, long long p_phoneNumber, const string& p_address, int p_bookingDate)
    : name(p_name), age(p_age), phoneNumber(p_phoneNumber), address(p_address), bookingDate(p_bookingDate) {}

// Getter methods to get name, age, phone number, address, and booking date
const string& Customer::getName() const {
    return name;
}

int Customer::getAge() const {
    return age;
}

long long Customer::getPhoneNumber() const {
    return phoneNumber;
}

const string& Customer::getAddress() const {
    return address;
}

int Customer::getBookingDate() const {
    return bookingDate;
}

// Setter methods to set different values
void Customer::setName(const string& new_name) {
    name = new_name;
}

void Customer::setAge(int new_age) {
    age = new_age;
}

void Customer::setPhoneNumber(long long new_phoneNumber) {
    phoneNumber = new_phoneNumber;
}

void Customer::setAddress(const string& new_address) {
    address = new_address;
}

void Customer::setBookingDate(int new_bookingDate) {
    bookingDate = new_bookingDate;
}

