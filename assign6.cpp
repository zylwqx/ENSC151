/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 6
 * assign6.cpp -- Program that allows the user to solve Thermal Conductivity Problems by selecting which varaible to solve for.
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
#include <cmath>

using namespace std;
double H, A, T2, T1, X, k;
    
double thermalConductivity(){
    cout << "Enter H (rate of heat transfer, W): " << endl;
    cin >> H;
    cout << "Enter A (cross-sectional area, m^2): " << endl;
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K): " << endl;
    cin >> T1;
    cout << "Enter T2 (temp. at side 2, K): " << endl;
    cin >> T2;
    cout << "Enter X (thickness, m): " << endl;
    cin >> X;
    k = (H*X)/(A*(T2 - T1));
    return k, H, A, T1, T2, X;
}

double tempSide2(){
    cout << "Enter H (rate of heat transfer, W): " << endl;
    cin >> H;
    cout << "Enter k (thermal conductivity, W/m-K): " << endl;
    cin >> k;
    cout << "Enter A (cross-sectional area, m^2): " << endl;
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K): " << endl;
    cin >> T1;
    cout << "Enter X (thickness, m): " << endl;
    cin >> X;
    T2 = (H*X)/(A*k) + T1;
    return T2, H, A, k, T1, X;
}

double thickness(){
    cout << "Enter H (rate of heat transfer, W): " << endl;
    cin >> H;
    cout << "Enter k (thermal conductivity, W/m-K): " << endl;
    cin >> k;
    cout << "Enter A (cross-sectional area, m^2): " << endl;
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K): " << endl;
    cin >> T1;
    cout << "Enter T2 (temp. at side 2, K): " << endl;
    cin >> T2;
    X = (A*k*(T2 - T1))/H;
    return X, H, A, k, T1, T2;
}

int main(){
    int choice;
    for (int trials = 0; trials < 3; trials++){
        cout << "Please select one of the following options:\n1) k\n2) T2\n3) X\n0) Exit\nSelection: " << endl;
        cin >> choice;
        if (choice == 1){
            thermalConductivity();
        } else if (choice == 2){
            tempSide2();
        } else if (choice == 3){
            thickness();
        } else if (choice == 0){
            cout << "Program exiting." << endl;
            exit(0);
            return 0;
        }
        cout << "------------------------------------------------" << endl;
        cout << "H = " << H << " W" << endl;
        cout << "k = " << k << " W/mK" << endl;
        cout << "A = " << A << " m^2" << endl;
        cout << "T1 = " << T1 << " K" << endl;
        cout << "T2 = " << T2 << " K" << endl;
        cout << "X = " << X << " m" << endl;
    }
        return 0;
}