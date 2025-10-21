/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 3
 * asign3.cpp -- Program to compute the distance and time a cyclist will travel
 * 
 * Input: Initial speed (km/h)
 *        Speed after 1 minute (km/h)
 * Output: Deceleration (m/s^2)
 *         Time to stop (minutes and seconds)
 *         Distance to stop (meters)
 * 
 * Author: Kevin Poon
 *
 *******************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/******************************************************************
 * Description -- Gives users the description of the program
 *
 * Parameters: none
 * Modifies: cout -- Outputs the description
 *
 * Pre condition -- All inputs are positive numbers
 * 
 * Returns: 0
 *******************************************************************/

void description() {
    cout << "This program estimates how far and how long a cyclist will travel \nwithout pedaling, assuming constant deceleration." << endl;
}

/******************************************************************
 * finding_acceleration -- Calculates for acceleration
 *
 * Parameters: u: initial speed (m/s)
 *             v: speed after 1 minute (m/s)
 * Modifies: none
 *
 * Pre condition -- All inputs are positive numbers
 * 
 * Returns: a: acceleration (m/s^2)
 *******************************************************************/
double finding_acceleration(double u, double v) {
    double a = (v - u) / (60.0); // Convert 1 minute to hours for deceleration calculation
    return a; 
}

/******************************************************************
 * finding_time -- Calculates for time
 *
 * Parameters: u: initial speed (m/s)
 *             a: acceleration (m/s^2)
 * Modifies: none
 *
 * Pre condition -- All inputs are positive numbers
 * 
 * Returns: t: acceleration (m/s^2)
 *******************************************************************/

double finding_time(double u, double a) {
    double t = -u / a; // Time to stop in hours
    return t;
}

/******************************************************************
 * finding_distance -- Calculates for distance
 *
 * Parameters: u: initial speed (m/s)
 *             a: acceleration (m/s^2)
 *             t: time (s)
 * Modifies: none
 *
 * Pre condition -- None
 * 
 * Returns: s: distance (m)
 *******************************************************************/

double finding_distance(double u, double a, double t) {
    double s = u * t + 0.5 * a * t * t; // Distance covered until stop in km
    return s;
}

/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifies: cout, cin -- Prompts the use to input the following: 
 *                      - Initial Speed
 *                      - Speed after 1 minute
 *
 * Pre condition -- All inputs are positive numbers
 * 
 * Returns: 0
 *******************************************************************/

int main() {
    description();
    double kmh0, kmh1, v0, v1;

    // Speed Inputs
    cout << "Enter initial speed (km/h):" << endl;
    cin >> kmh0;
    cout << "Enter speed after 1 minute (km/h):" << endl;
    cin >> kmh1;
    
    // Convert to m/s
    v0 = kmh0 / 3.6;
    v1 = kmh1 / 3.6;

    // Finding values
    double a = finding_acceleration(v0, v1); // m/s^2
    double t = finding_time(v0, a); // seconds
    int d = round(finding_distance(v0, a, t)); // meters
    

    // Convert time to minutes and seconds
    int tm = t / 60; // minutes
    int ts = round((t - tm * 60)); // seconds
    
    // Output results
    cout <<"deceleration = "<<-a<<", minutes = "<<tm<<", seconds = "<<ts<<", distance = "<<d<< endl;
    
    return 0;
}