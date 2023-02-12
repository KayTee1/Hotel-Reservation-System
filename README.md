# Simple Hotel-Reservation-System

My first larger C++ Project that i did in my Introduction to C++ -course

A simple program to manage customer check-ins and check-outs at a hotel. The program allows customers to select between checking in and checking out, and provides options for inputting customer information and viewing details of their stay. The program also generates a random reservation number for each customer, and displays a summary of their stay details.

# Functions
The program has two main functions:

- newCustomer: This function allows a new customer to check into the hotel, and inputs their information, including first name, last name, age, room type, and number of nights stayed. It also generates a random reservation number and displays a summary of the customer's stay details.

- leavingCustomer: This function allows a customer to check out of the hotel, and deletes their information.


# Input Validation

The program includes an inputValidation function, which validates user input to ensure that it falls within a specified range. This function takes three parameters: target, x, and y. Target is the value to be validated, x is the minimum value, and y is the maximum value. If the input is not within the specified range, the function will prompt the user to enter a valid value.