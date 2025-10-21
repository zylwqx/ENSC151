/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 4
 * asign4.cpp -- Program to rearrange a string based on '*' positions.
 * 
 * Input: A string containing exactly three '*' characters. (Word1*Word2*Word3*Word4)
 * Output: The rearranged string with parts separated by spaces. (Word4 Word3 Word2 Word1)
 * 
 * Author: Kevin Poon
 *
 *******************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/******************************************************************
 * Main -- 
 *
 * Parameters: none
 * Modifies: cout, cin -- Prompts the user to input a string containing exactly three '*' characters.
 *           getline -- Reads the entire line including spaces.
 *           input.find -- Finds the positions of the '*' characters.
 *           input.substr -- Extracts the parts of the string between the '*' characters.
 *           tolower, toupper -- Changes the case of the first character of the first and last parts.
 *
 * Pre condition -- The input string contains exactly three '*' characters.
 * 
 * Returns: 0
 *******************************************************************/

int main(){
    string input; // input string
    getline(cin, input); // read the whole line including spaces

    size_t pos1 = input.find('*'); // find the position of the first '*'
    size_t pos2 = input.find('*', pos1 + 1); // find the position of the second '*'
    size_t pos3 = input.find('*', pos2 + 1); // find the position of the third '*'

    string part1 = input.substr(0, pos1); // extract the first part
    string part2 = input.substr(pos1 + 1, pos2 - pos1 - 1); // extract the second part
    string part3 = input.substr(pos2 + 1, pos3 - pos2 - 1); // extract the third part
    string part4 = input.substr(pos3 + 1); // extract the fourth part

    string output = part4 + " " + part3 + " " + part2 + " " + part1; // combine in reverse order

    cout << output << endl; // print the output string

    return 0;

}

