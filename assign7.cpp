#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cctype>


using namespace std;

int main(){
    int inputCount;
    string inputNumbers;
    double sum = 0.0;
    double value;
    double maxValue = 0.0;
    string positions = "";

    cout << "Please state the number of inputs: " << endl;
    cin >> inputCount;

    while (true){
        if (inputCount >= 0 && inputCount <= 100){
            break;
        } else {
            cout << "Invalid input: number must be between 1 and 100." << endl;
            cout << "Please state the number of inputs: ";
            cin >> inputCount;
        }
    }


    cout << "Please input all " << inputCount << " values separated by whitespace: " << endl;

    for

    cout << "The number of values above the average is " << sum/inputCount << endl;
    cout << "The maxim value was " << maxValue << endl;
    cout << "The maximum occurred at the following positions: "<< positions << endl;

    return 0;
    
}