#include <iostream>

using namespace std;

string numbers;
double num1, num2, num3;
double sum = 0, avg;
double maxVal = -100e100, minVal = 100e100;


void threeNumbers(){
    cout << "Input 3 numbers separated by spaces" << endl;
    cin >> num1 >> num2 >> num3;
}

double average(){
    sum = num1 + num2 + num3;
    avg = sum/3;

    return avg;
}

void maxMin(){
    if (num1 > maxVal){
        maxVal = num1;
    }
    if (num2 > maxVal){
        maxVal = num2;
    }
    if (num3 > maxVal){
        maxVal= num3;   
    }
    if (num1 < minVal){
        minVal= num1;
    }
    if (num2 < minVal){
        minVal= num2;
    }
    if (num3 < minVal){
        minVal= num3;
    }
}

int main(){

    threeNumbers();
    average();
    maxMin();

    cout << "The average is: " << avg << endl;
    cout << "The max is: " << maxVal<< "\nThe min is: " << minVal<< endl;

    return 0;
    
}