#include <cmath>
#include <iostream>

using namespace std;

double addition(int num1, int num2, int den1, int den2){
    int num3;
    int den3;

    num3 = num1 * den2 + num2 * den1;
    den3 = den1 * den2;

    cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << num3 << "/" << den3 << " " << endl;
}

double subtraction(int num1, int num2, int den1, int den2){
    int num3;
    int den3;

    num3 = num1 * den2 - num2 * den1;
    den3 = den1 * den2;

    cout << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = " << num3 << "/" << den3 << " " << endl;
}

double multiplication(int num1, int num2, int den1, int den2){
    int num3;
    int den3;

    num3 = num1 * num2;
    den3 = den1 * den2;

    cout << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = " << num3 << "/" << den3 << " " << endl;
}

double division(int num1, int num2, int den1, int den2){
    int num3;
    int den3;

    num3 = num1 * den2;
    den3 = den1 * num2;

    cout << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = " << num3 << "/" << den3 << " " << endl;
}

int main(){
    int choice;
    int num1;
    int den1;
    int num2;
    int den2;
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
            addition(num1, num2, den1, den2);
        } else if (choice == 2){
            subtraction(num1, num2, den1, den2);
        } else if (choice == 3){
            multiplication(num1, num2, den1, den2);
        } else if (choice == 4){
            division(num1, num2, den1, den2);
        } else if (choice == 5){
            exit(0);
        }
    }
}