/* File: Prog4-Group6                                                                    Nader Tomas w10172066
* Assignment 4                                                                           Thales Teixeira Rodrigues w10173761
* 
* Purpose/ Objective: It provides a menu-driven interface for users to interact with the system. 
* Users can choose from various options like viewing available rooms, booking and unbooking rooms, and generating guest summaries. 
* Main calls all the classes created in the program. Also, The main function manages the overall control flow of the program, 
* using a loop to repeatedly display the menu and handle user input until the user chooses to exit the program.
*/


#include <iostream>
#include "Hotel.h"
#include "Room.h"
#include "Customer.h"
#include "Booking.h"

using namespace std;

void displayMenu() {
    cout << "***********************************" << endl;
    cout << "           Hotel Menu              " << endl;
    cout << "***********************************" << endl;
    cout << "1. Display Available Rooms" << endl;
    cout << "2. Book a Room" << endl;
    cout << "3. Display Booked Rooms" << endl;
    cout << "4. Display Guest Summary" << endl;
    cout << "5. Unbook a Room" << endl;
    cout << "6. Exit" << endl;
    cout << "***********************************" << endl;
}

int main() {
    // Create a hotel with a minimum of 50 rooms, including 20 premium rooms
    Hotel hotel(30, 30, 20);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.roomsAvailable();
            break;
        case 2: {
            // Get customer details and room number, then book the room
            string name, address;
            int age, roomNum, bookingDate;
            long long phoneNumber;

            cout << "Enter customer name: ";
            cin.ignore(); // Clear newline from buffer
            getline(cin, name);

            cout << "Enter customer age: ";
            cin >> age;

            cout << "Enter customer phone number: ";
            cin >> phoneNumber;

            cout << "Enter customer address: ";
            cin.ignore(); // Clear newline from buffer
            getline(cin, address);

            cout << "Enter booking date (DDMMYYYY): ";
            cin >> bookingDate;

            cout << "Enter room number: ";
            cin >> roomNum;

            Customer customer(name, age, phoneNumber, address, bookingDate);
            hotel.bookRoom(roomNum, customer);
            break;
        }
        case 3:
            hotel.roomsBooked();
            break;
        case 4: {
            // Get customer name
            string name;
            cout << "Enter customer name: ";
            cin.ignore(); // Clear newline from buffer
            getline(cin, name);

            // Search for the customer in bookings
            bool customerFound = false;
            for (const auto& booking : hotel.getBookings()) {
                const Customer& bookedCustomer = booking.getBookingCustomer();
                if (bookedCustomer.getName() == name) {
                    hotel.guestSummary(bookedCustomer);
                    customerFound = true;
                    break;
                }
            }

            if (!customerFound) {
                cout << "Customer not found in bookings." << endl;
            }
            break;
        }
        case 5: {
            // Unbook a room
            int roomNum;
            cout << "Enter room number to unbook: ";
            cin >> roomNum;

            hotel.unbookRoom(roomNum);
            break;
        }
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
