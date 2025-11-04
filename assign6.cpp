/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 6
 * assign6.cpp -- Program that allows the user to solve Thermal Conductivity Problems by selecting which varaible to solve for.
 * 
 * Input: Known Variables
 * Output: All variables
 * 
 * Author:Kevin Poon
 *
 *******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
double H, A, T2, T1, X, k;

    

double thermalConductivity(){
    cout << "Enter H (rate of heat transfer, W):" << endl; // Ask user for the value of the rate of heat transfer
    cin >> H;
    cout << "Enter A (cross-sectional area, m^2):" << endl; // Ask user for the value of the cross-sectional area
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K):" << endl; // Ask user for the value of the temperature at side 1
    cin >> T1;
    cout << "Enter T2 (temp. at side 2, K):" << endl; // Ask user for the value of the temperature at side 2
    cin >> T2;
    cout << "Enter X (thickness, m):" << endl; // Ask user for the value of the thickness between materials
    cin >> X;
    k = (H*X)/(A*(T2 - T1));
    return k, H, A, T1, T2, X;
}

/******************************************************************
 * tempSide2 -- Allows user to input known variables to calculate for the tempurature of side 2
 *
 * Parameters: none
 * Modifies: cout, cin
 * 
 * Input: All known variables:
 *            - H, k, A, T1, X
 * Output: The tempurature at side 2
 *
 * Pre condition -- All inputs are numbers
 * 
 * Returns: 0
 *******************************************************************/

double tempSide2(){
    cout << "Enter H (rate of heat transfer, W):" << endl; // Ask user for the value of the rate of heat transfer
    cin >> H;
    cout << "Enter k (coefficient of thermal conductivity, W/m-K):" << endl; // Ask user for the value of the coefficient of thermal conductivity
    cin >> k;
    cout << "Enter A (cross-sectional area, m^2):" << endl; // Ask user for the value of the cross-sectional area
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K):" << endl;  // Ask user for the value of the temperature at side 1
    cin >> T1;
    cout << "Enter X (thickness, m):" << endl; // Ask user for the value of the thickness between materials
    cin >> X;
    T2 = (H*X)/(A*k) + T1;
    return T2, H, A, k, T1, X;
}

/******************************************************************
 * thichness -- Allows user to input known variables to calculate for the thickness between materials
 *
 * Parameters: none
 * Modifies: cout, cin
 * 
 * Input: All known variables:
 *            - H,, K A, T1, T2
 * Output: The thickness between materials
 *
 * Pre condition -- All inputs are numbers
 * 
 * Returns: 0
 *******************************************************************/

double thickness(){
    cout << "Enter H (rate of heat transfer, W):" << endl; // Ask user for the value of the rate of heat transfer
    cin >> H;
    cout << "Enter k (coefficient of thermal conductivity, W/m-K):" << endl; // Ask user for the value of the coefficient of thermal conductivity
    cin >> k;
    cout << "Enter A (cross-sectional area, m^2):" << endl; // Ask user for the value of the cross-sectional area
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K):" << endl; // Ask user for the value of the temperature at side 1
    cin >> T1;
    cout << "Enter T2 (temp. at side 2, K):" << endl; // Ask user for the value of the temperature at side 2
    cin >> T2;
    X = (A*k*(T2 - T1))/H;
    return X, H, A, k, T1, T2;
}

/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifiers: cout, cin
 * 
 * Input: Cacluation Choice
 * Output: All variable values in the calculation
 * 
 * Pre Conditions: All inputs are numbers
 *
 * Returns: 0 
 *******************************************************************/

int main(){
    int choice;
    for (int trials = 0; trials < 9; trials++){
        cout << "Please select one of the following options:\n1) k\n2) T2\n3) X\n0) Exit\nSelection: " << endl; // Displays options for user to choose
        cin >> choice; // saves the users choice
        if (choice == 1){ // compares the users choice to possible outcomes
            thermalConductivity(); // user chose to calculate for thermal conductivity
        } else if (choice == 2){
            tempSide2(); // user chose to calculate for temperature at side 2
        } else if (choice == 3){
            thickness(); // user chose to calculate for the thickness
        } else if (choice == 0){
            cout << "Program exiting." << endl; // user chose to exit the program
            exit(0);
            return 0;
        }
        cout << "------------------------------------------------" << endl;
        cout << "H = " << H << " W" << endl; // prints out the value of the rate of heat transfer
        cout << "k = " << k << " W/m-K" << endl; // prints out the value of thermal conductivity
        cout << "A = " << A << " m^2" << endl; // prints out the cross sectional area
        cout << "T1 = " << T1 << " K" << endl; // prints out the temperature at side 1
        cout << "T2 = " << T2 << " K" << endl; // prints out the temperature at side 2
        cout << "X = " << X << " m" << endl; // prints out the thickness
    }
        return 0;
}