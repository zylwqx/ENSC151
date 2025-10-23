#include <cmath>
#include <iostream>

using namespace std;

int num3;
int den3;
int ratio;

int rationalize(){
    for (int i = 1; i < 100; i++){
        if (num3 % i == 0 && den3 % i == 0){
            ratio = i;
        }
    }
    return 0;
}

double addition(int num1, int num2, int den1, int den2){
    num3 = num1 * den2 + num2 * den1;
    den3 = den1 * den2;
    rationalize();
    return 0;
}

double subtraction(int num1, int num2, int den1, int den2){
    num3 = num1 * den2 - num2 * den1;
    den3 = den1 * den2;
    rationalize();
    return 0;
}

double multiplication(int num1, int num2, int den1, int den2){
    num3 = num1 * num2;
    den3 = den1 * den2;
    rationalize();
    return 0;
}    

double division(int num1, int num2, int den1, int den2){
    num3 = num1 * den2;
    den3 = den1 * num2;
    rationalize();
    return 0;
}



int main(){
    int choice;
    int num1;
    int den1;
    int num2;
    int den2;
    string op;

    while (true){
        cout << "Rational number calculator" << endl;
        cout << "1) Add\n2) Subtract\n3) Multiply\n4) Divide\n5) Exit\n" << endl;
        cout << "Please select an operation from above (1 - 5): " << endl;
        cin >> choice;

        cout << "Please enter the left operand numerator followed by denominator: " << endl;
        cin >> num1 >> den1;
        cout << "Please enter the right operand numerator followed by denominator: " << endl;
        cin >> num2 >> den2;

        if (choice == 1){
            op = " + ";
            addition(num1, num2, den1, den2);
        } else if (choice == 2){
            op = " - ";
            subtraction(num1, num2, den1, den2);
        } else if (choice == 3){
            op = " * ";
            multiplication(num1, num2, den1, den2);
        } else if (choice == 4){
            op = " / ";
            division(num1, num2, den1, den2);
        } else if (choice == 5){
            exit(0);
        }
        break;
    }
    cout << num1 << "/" << den1 << op << num2 << "/" << den2 << " = " << num3 << "/" << den3 << endl;
    cout << ratio;
}