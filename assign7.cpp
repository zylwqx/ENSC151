/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 7
 * assign7.cpp -- Program that takes inputted numbers and outputs the maximum, where the maximum is, and how many numbers are above the average
 * 
 * Input: x and x amount of numbers
 * Output: # of numbers above the average, the maximum number inputted, and the positions of the maximum number
 * 
 * Author:Kevin Poon
 *
 *******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/******************************************************************
 * main -- 
 *
 * Parameters: none
 * Modifies: cout -- ask for user input, outputs result
 *           cin -- takes user input
 *           vector -- create arrays
 *           to_string -- converts numbers into a string
 *           stod -- converts string into a double
 * 
 * Input: All known variables:
 *            - H, A, T1, T2, X
 * Output: The coefficient of thermal conductivity
 *
 * Pre condition -- All inputs are numbers
 * 
 * Returns: 0
 *******************************************************************/

int main(){
    int inputCount;
    string inputNumbers;
    double sum = 0.0;
    double value;
    double maximum = 0.0;
    string positions = "";
    double avg;

    cout << "Please state the number of inputs: " << endl; // prompts user for the number of numbers they will input later
    cin >> inputCount; // saves the amount of numbers the user wants for furture comparisons

    while (true){ // ensures user inputs a number between [1, 100]
        if (inputCount >= 1 && inputCount <= 100){ 
            break;
        } else {
            cout << "Invalid input: number must be between 1 and 100." << endl; // tells user their input is invalid
            cout << "Please state the number of inputs: "; // prompts user for the number of numbers they will input later
            cin >> inputCount;
        }
    }


    cout << "Please input all " << inputCount << " values separated by whitespace: " << endl; // prompts user to input x amount of numbers
    vector<double> numbers(inputCount); // creates an array for the numbers
    vector<string> rawNum(inputCount); // creates an array for the raw numbers in text form

    for (int i = 0; i < inputCount; i++){
        string nums; // gets raw number in text
        cin >> nums;
        rawNum[i] = nums; // stores raw number as text
        numbers[i] = stod(nums); // converts the number (which was a string) into an double (number)
        sum += numbers[i]; // stores number as a real number
    }

    int rawI; // list position

    for (int i = 0; i < inputCount; i++){
        if (numbers[i] > maximum){ // checked if the number in x position is bigger than the current biggest number
            maximum = numbers[i]; // makes maxmimum the max number
            rawI = i; // makes sure I can recall maximum position in the array
        }
    }

    for (int i = 0; i < inputCount; i++){
        if (numbers[i] == maximum){
            positions += to_string(i) + " "; // adds position number to a array
        }
    }

    avg = sum/inputCount;
    int numAbove = 0;
    for (int i = 0; i < inputCount; i++){
        if (numbers[i] > avg){ // checks if number is above the avarage
            numAbove += 1; // increases amount of numbers above the average by 1
        }
    }

    cout << "The number of values above the average is " << numAbove << "." << endl; // prints out amount of numbers above the average
    cout << "The maxim value was " <<  rawNum[rawI] << "." << endl; // prints out the number in raw text so it keeps the 0 at the end
    cout << "The maximum occurred at the following positions: "<< positions << endl; // prints out which number position the max occurs at

    return 0;
    
}

/******************************************************************
 * $RCSfile: assig7.cpp$ 
 * $Revision$
 * $Oct 30, 2025$
 * $State$
 *
 * REVISION HISTORY
 *
 * $Log: assign8.cpp$
 * 
 * Revision 4 Oct 30, 2025
 * - Added washer.cpp style comments
 * 
 * Revision 3 Oct 26, 2025
 * - Figured I could use both string and double vectors as number positions would be the same
 * 
 * Revision 2 Oct 26, 2025
 * - Tried finding a way to past the test case. 
 * - Attempted to use string vector but cant do math functions with string
 * 
 * Revision 1 Oct 26, 2025
 * - Initial creation of variables and functions
 * - Completed majority of the code
 * - Failed 1 test case
 ******************************************************************/