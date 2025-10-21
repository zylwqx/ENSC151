#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>


using namespace std;

int main(){
    int inputCount;
    string inputNumbers;
    double sum = 0.0;
    double value;
    double maximum = 0.0;
    string positions = "";
    double avg;

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

    vector<double> numbers(inputCount);
    for (int i = 0; i < inputCount; i++){
        cin >> numbers[i];
        sum += numbers[i];
    }

    for (int i = 0; i < inputCount; i++){
        if (numbers[i] > maximum){
            maximum = numbers[i];
        }
    }

    for (int i = 0; i < inputCount; i++){
        if (numbers[i] == maximum){
            positions += to_string(i) + " ";
        }
    }

    avg = sum/inputCount;
    int numAbove = 0;
    for (int i = 0; i < inputCount; i++){
        if (numbers[i] > avg){
            numAbove += 1;
        }
    }

    cout << "The number of values above the average is " << numAbove << "." << endl;
    cout << "The maximum value was " << maximum << "." << endl;
    cout << "The maximum occurred at the following positions: "<< positions << endl;

    return 0;
    
}