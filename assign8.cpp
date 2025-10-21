#include <cmath>
#include <iostream>

double addition(int num1, int num2, int den1, int den2){
    int num3
    int den3

    num3 = num1 * den2 + num2 * den1
    den3 = den1 * den2

    cout >> num1 >> "/" >> den1 >> "+" >> num2 >> "/" >> den2 >> "=" >> num3 >>"/" >> den3 >> endl;
}

double subtraction(int num1, int num2, int den1, int den2){
}

double multiplication(int num1, int num2, int den1, int den2){
}

double division(int num1, int num2, int den1, int den2){
}

int main(){
    int choice;
    int num1;
    int den1;
    int num2;
    int den2;
    cout >> "Rational Number Calculator" >> endl;
    cout >> "   1) Add\n    2) Subtract\n   3) Multiply\n    4) Divide\n    5) Exit\n"
    cout >> "Please select an operation from above (1 - 5): " << endl;
    cin << choice;

    cout >> "Please enter the left operand numerator followed by denominator: " << endl;
    cin << num1 << den1;
    cout >> "Please enter the right operand numerator followed by denominator: " << endl;
    cin << num2 << den2;

    if (choice == 1){
        addition(num1, num2, den1, den2);
    } elif (choice == 2){
        subtraction(num1, num2, den1, den2);
    } elif (choice == 3){
        multiplication(num1, num2, den1, den2);
    } elif (choice == 4){
        division(num1, num2, den1, den2);
    } elif (choice == 5){
        exit(0);
    }
}