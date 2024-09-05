/*File: Prog4-Group6                                                                  Nader Tomas w10172066
* Assignment 4                                                                        Thales Teixeira Rodrigues w10173761
* 
* Description: Declaration of the Customer class, representing a customer who may book a room in the hotel. 
* 
* Public members include the default constructor and parameterized constructor to initialize customer attributes.
* Getters and Setters: Methods to access and modify private member variables.
* Private memebers represent the name, age, phone number, address, and booking date of the customer
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    string name;
    int age;
    long long phoneNumber;
    string address;
    int bookingDate;

public:
    Customer(); // Default constructor
    Customer(const string& p_name, int p_age, long long p_phoneNumber = 0, const string& p_address = "", int p_bookingDate = 0); // Parameterized constructor

    // Getter methods
    const string& getName() const;
    int getAge() const;
    long long getPhoneNumber() const;
    const string& getAddress() const;
    int getBookingDate() const;

    // Setter methods
    void setName(const string& new_name);
    void setAge(int new_age);
    void setPhoneNumber(long long new_phoneNumber);
    void setAddress(const string& new_address);
    void setBookingDate(int new_bookingDate);

};

#endif