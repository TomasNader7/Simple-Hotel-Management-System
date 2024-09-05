<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  
</head>
<body>

<h1>Hotel Management System</h1>
<p>
  <strong>Program Name:</strong> Hotel Management System<br>
  <strong>Authors:</strong> Nader Tomas<br>
</p>

<h2>Purpose</h2>
<p>
  The Hotel Management System is a C++ program that provides a simple interface for managing hotel operations. The program allows users to view available rooms, book/unbook rooms, display booked rooms, and generate guest summaries. It is designed to be easy to use, with a menu-driven interface to guide users through the various operations.
</p>

<h2>Features</h2>
<ul>
  <li>Display available rooms.</li>
  <li>Book a room by entering customer details.</li>
  <li>View all booked rooms.</li>
  <li>Generate a guest summary for a specific customer.</li>
  <li>Unbook a room.</li>
  <li>Exit the program.</li>
</ul>

<h2>How It Works</h2>
<p>
  The program consists of several classes that handle different aspects of the hotel management system:
</p>

<h3>1. <code>Hotel</code></h3>
<p>
  The <code>Hotel</code> class is responsible for managing the hotel, including handling available rooms, bookings, and guest summaries. It initializes a hotel with a specified number of rooms and provides methods to:
</p>
<ul>
  <li>Display available rooms (<code>roomsAvailable()</code>).</li>
  <li>Book a room (<code>bookRoom()</code>).</li>
  <li>Unbook a room (<code>unbookRoom()</code>).</li>
  <li>Display booked rooms (<code>roomsBooked()</code>).</li>
  <li>Generate a guest summary (<code>guestSummary()</code>).</li>
</ul>

<h3>2. <code>Room</code></h3>
<p>
  The <code>Room</code> class represents individual rooms in the hotel. Each room has attributes like:
</p>
<ul>
  <li>Room number</li>
  <li>Room type (Single, Double, Suite)</li>
  <li>Price per night</li>
  <li>Number of beds</li>
  <li>Availability (booked or not)</li>
</ul>
<p>
  The class provides methods to book and unbook rooms, as well as display room information.
</p>

<h3>3. <code>Customer</code></h3>
<p>
  The <code>Customer</code> class represents customers who book rooms in the hotel. It stores customer details like:
</p>
<ul>
  <li>Name</li>
  <li>Age</li>
  <li>Phone number</li>
  <li>Address</li>
  <li>Booking date</li>
</ul>
<p>
  This class includes getter and setter methods to retrieve or modify customer information.
</p>

<h3>4. <code>Booking</code></h3>
<p>
  The <code>Booking</code> class links a <code>Room</code> and a <code>Customer</code> object together to create a booking. It provides methods to retrieve information about the booked room and customer.
</p>

<h2>Menu Options</h2>
<p>
  The program offers the following menu options to the user:
</p>
<pre>
***********************************
           Hotel Menu              
***********************************
1. Display Available Rooms
2. Book a Room
3. Display Booked Rooms
4. Display Guest Summary
5. Unbook a Room
6. Exit
***********************************
</pre>

<h3>Menu Functionality</h3>
<ul>
  <li><strong>Option 1:</strong> Displays all available rooms.</li>
  <li><strong>Option 2:</strong> Prompts the user to enter customer details (name, age, phone number, address, booking date) and books a room if available.</li>
  <li><strong>Option 3:</strong> Displays all rooms that are currently booked and shows the customer who booked each room.</li>
  <li><strong>Option 4:</strong> Prompts the user to enter a customer name and displays a summary of the customer's details if they have a booking.</li>
  <li><strong>Option 5:</strong> Prompts the user to enter a room number and unbooks the room if it is currently booked.</li>
  <li><strong>Option 6:</strong> Exits the program.</li>
</ul>

<h2>Installation and Usage</h2>
<ol>
  <li>Clone or download the repository containing the <code>hotelManagementSystem.cpp</code> file and its dependencies.</li>
  <li>Ensure you have a C++ compiler (e.g., g++) installed on your machine.</li>
  <li>Compile the program:
    <pre><code>g++ -o hotelManagementSystem hotelManagementSystem.cpp Hotel.cpp Room.cpp Customer.cpp Booking.cpp</code></pre>
  </li>
  <li>Run the program:
    <pre><code>./hotelManagementSystem</code></pre>
  </li>
  <li>Follow the menu prompts to interact with the system.</li>
</ol>

<h2>File Descriptions</h2>
<ul>
  <li><code>hotelManagementSystem.cpp</code>: The main program file, containing the menu and program flow.</li>
  <li><code>Hotel.h</code> and <code>Hotel.cpp</code>: Define the <code>Hotel</code> class and its methods for managing rooms and bookings.</li>
  <li><code>Room.h</code> and <code>Room.cpp</code>: Define the <code>Room</code> class and its methods for handling room-specific operations.</li>
  <li><code>Customer.h</code> and <code>Customer.cpp</code>: Define the <code>Customer</code> class and its methods for managing customer details.</li>
  <li><code>Booking.h</code> and <code>Booking.cpp</code>: Define the <code>Booking</code> class and its methods for linking customers and rooms.</li>
</ul>

<h2>Example Usage</h2>
<pre>
Enter your choice: 1
Available Rooms:
Room 1: Single - $50 per night, 2 beds
Room 2: Single - $50 per night, 2 beds
...

Enter your choice: 2
Enter customer name: John Doe
Enter customer age: 30
Enter customer phone number: 1234567890
Enter customer address: 123 Street Name, City
Enter booking date (DDMMYYYY): 25092023
Enter room number: 1
Room 1 booked by John Doe.

Enter your choice: 4
Enter customer name: John Doe
Guest Summary:
Customer Name: John Doe
Customer Age: 30
Customer Phone Number: 1234567890
Customer Address: 123 Street Name, City
Booking Date: 25/09/2023
</pre>

<h2>Contributions</h2>
<p>
  The following contributors created this program:
</p>
<ul>
  <li>Nader Tomas</li>
</ul>

<h2>License</h2>
<p>
  This project is open-source and licensed under the MIT License.
</p>

</body>
</html>
