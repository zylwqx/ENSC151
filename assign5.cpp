/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 5
 * assign5.cpp -- Program to convert compass headings to compass bearings.
 * 
 * Input: A heading in degrees [0, 360).
 * Output: The corresponding compass bearing or an error message for invalid input.
 * 
 * Author: Kevin Poon
 *
 *******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/******************************************************************
 * Main -- 
 *
 * Parameters: none
 * Modifies: cout -- Prompts the user to input a heading in degrees.
 *           cin -- Reads the heading input.
 *
 * Pre condition -- The input heading is a number in the range [0, 360).
 * 
 * Returns: 0
 *******************************************************************/

int main(){
    for (int trials = 0; trials < 5; trials++){
        double heading;
        cout << "Please enter heading [0, 360): " << endl;
        cin >> heading;
        if (heading >= 0 && heading < 360){
            if (heading >= 0 && heading < 90) {
                cout << "Heading of : " << heading << " degrees is North " << heading <<" East" << endl;
            } else if (heading < 360 && heading > 270) {
                cout << "Heading of : " << heading << " degrees is North " << 360 - heading <<" West" << endl;
            } else if (heading < 270 && heading > 180) {
                cout << "Heading of : " << heading << " degrees is South " << 90-(270 - heading) <<" West" << endl;
            } else if (heading < 180 && heading > 90) {
                cout << "Heading of : " << heading << " degrees is South " << 180 - heading <<" East" << endl;
            } else if (heading == 180) {
                cout << "Heading of : " << heading << " degrees is South " << endl;
            } else if (heading == 360) {
                cout << "Heading of : " << heading << " degrees is North " << endl;
            } else if (heading == 270) {
                cout << "Heading of : " << heading << " degrees is West " << endl;
            } else if (heading == 90) {
                cout << "Heading of : " << heading << " degrees is East " << endl;
            } 
        }
        else {
            cout << heading << " is an invalid input." << endl;
        }
    }
}