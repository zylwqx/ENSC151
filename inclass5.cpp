#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
vector<double> numbers(3);

void inputNumbers(){
    double num;
    cout << "Please enter three numbers seperated by blank space: " << endl;
    for(int i = 0; i < 3; i++){
        cin >> num;
        numbers[i] = num;
    }
}

double average(){
    return (numbers[0]+numbers[1]+numbers[2])/3;
}

void maxMin(double &max, double &min){
    for(int i = 0; i < 3; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if (numbers[i] < min){
            min = numbers[i];
        }
    }
}

int main(){
    double max = -100e100, min = 100e100;;
    inputNumbers();
    maxMin(max, min);
    cout << "The average is: " << average() << endl;
    cout << "The max is: " << max << endl;
    cout << "The min is: " << min << endl;
}