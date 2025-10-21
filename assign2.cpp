/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 2
 * asign2.cpp -- Program to compute the duration of a projectile's flight and its height.
 * 
 * Input: Distance to target
 *        Launch angle (degrees)
 *        Launch speed (m/s)
 * Output: Duration of flight
 *         Height at the target
 *
 * Author: Kevin Poon
 *
 *******************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

/******************************************************************
 * Description -- Gives users the description of the program
 *
 * Parameters: none
 * Modifies: cout -- Outputs the description
 *
 * Returns: Nothing
 *******************************************************************/

void description() {
    cout << "This program computes the duration of a projectile's flight and its height." << endl;
}

/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifies: cout, cin -- Prompts the use to input the following: 
 *                      - Distance to target
 *                      - Launch angle (degrees)
 *                      - Launch speed (m/s)
 *
 * Pre condition -- All inputs are positive numbers
 * 
 * Returns: 0
 *******************************************************************/

int main() {
    description();
    double s, theta_d, v;
    const double g = 9.81;

    cout << "Enter the distance to the target (m):\n"; // prompts user to enter distance to the targer
    cin >> s;
    cout << "Enter the launch angle (degrees):\n"; // prompts user to enter launch angle
    cin >> theta_d;
    cout << "Enter the launch speed (m/s):\n"; // prompts user to enter launch speed
    cin >> v; 

    double theta_r = theta_d * M_PI / 180; // converts angle in degrees to radians
    double time = s / (v * cos(theta_r)); // calculate duration of the flight
    double height = v * sin(theta_r) * time - 0.5 * g * time * time; // calculate the height of the object when it is at the targer

    cout << "Duration of flight: " << time << " s"<<endl; // outputs the flight duration
    cout << "Height at the target: " << height << " m" << endl; // outputs the height at the target

    return 0;
}