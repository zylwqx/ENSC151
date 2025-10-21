/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 1
 * asign1.cpp -- Program to compute the distance jogged by Arnie.
 * 
 * Input: Initial Strides
 *        Final Strides
 *        Time Jogged (hours and minutes)
 * Output: Average Stride Rate
 *         Total Distance Jogged
 * 
 * Author: Kevin Poon
 *
 *******************************************************************/

#include <iostream>
using namespace std;

/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifies: cout, cin -- Prompts the user to input the following:
 *                      - Initial Strides
 *                      - Final Strides
 *                      - Time Jogged (hours and minutes)
 * 
 * Pre Conditions: All inputs are positive numbers
 *
 * Returns: 0 
 *******************************************************************/

int main() {
    double IS, FS, TH, TM;

    //ask for user input and store values
    cout << "Please enter the number of strides taken in the first minute: ";
    cin >> IS;
    cout << "Please enter the number of strides taken in the last minute: ";
    cin >> FS;
    cout << "Please enter the number of hours and minutes jogged (hh mm): ";
    cin >> TH >> TM;

    
    double avgStrides = (IS + FS) / 2.0; //Average of initial and final stride rates -- calcualted in strides/min
    int TT = TH * 60 + TM; //Converting time to total minutes

    //Output results
    cout << "Arnie's estimated average stride rate (strides/minute): " << avgStrides << std::endl;
    cout << "Total distance that Arnie has jogged (km): " << avgStrides * TT * 0.0075 << " km" << std::endl;

    return 0;
}   