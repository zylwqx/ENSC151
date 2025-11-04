    /******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 8
 * asign8.cpp -- Rational Calculator that takes two fractions and applies a chosen operation.
 * 
 * Input: Two fraction operands 
 * Output: Mathematical answer in reduced imporper fraction form
 * 
 * Author: Kevin Poon
 *
 *******************************************************************/
    
#include <cmath>
#include <iostream>

using namespace std;

int rnumL, rnumR, rnumS, rdenL, rdenR, rdenS; // creates reduced numerators and denominators variables as an integer
int numS, denS; // creates solution numerators and denominators variables as an integer

/******************************************************************
 * rationalize -- finds the ratio which reduces the operands and solution
 *
 * Parameters: numL, numR, numS, denL, denR, denS
 * Modifies: none
 *
 * Pre condition -- none
 * 
 * Returns: rationized numerators and denominators
 *******************************************************************/

double rationalize(int numL, int numR, int numS, int denL, int denR, int denS){

    if (denS < 0){ // ensures the negative is on the numerator
        numS = -numS;
        denS = -denS;
    }

    for (int i = 1; i < 100; i++){ // finds the GCD between [1,100)
        if (numS % i == 0 && denS % i == 0){ // finds the GCD for the solution and reduces the fraction
            rnumS = numS/i; // reduces
            rdenS = denS/i; // reduces
        }
        if (numL % i == 0 && denL % i == 0){ // finds the GCD for the left operand and reduces the fraction
            rnumL = numL/i; // reduces
            rdenL = denL/i; // reduces
        }
        if (numR % i == 0 && denR % i == 0){ // finds the GCD for the right operand and reduces the fraction
            rnumR = numR/i; // reduces
            rdenR = denR/i; // reduces
        }
    }

    return rnumL, rnumR, rnumS, rdenL, rdenR, rdenS; // returns rationalized numerators and denominators
}

/******************************************************************
 * addition -- adds the operands and saves the solutions numerator and denomimator
 *
 * Parameters: numL, numR, numS, denL, denR, denS
 * Modifies: none
 *
 * Pre condition -- none
 * 
 * Returns: the solutions numerator and denominator
 *******************************************************************/

double addition(int numL, int numR, int denL, int denR){
    numS = numL * denR + numR * denL; // cross multiplies then adds for the numerator value
    denS = denL * denR; // multiply denominator for common denominator
    
    return numS, denS; // returns solutions numerator and denominator 
}

/******************************************************************
 * addition -- subtracts the left operand from the right operand and saves the solutions numerator and denominator
 *
 * Parameters: numL, numR, numS, denL, denR, denS
 * Modifies: none
 *
 * Pre condition -- none
 * 
 * Returns: the solutions numerator and denominator
 *******************************************************************/

double subtraction(int numL, int numR, int denL, int denR){
    numS = numL * denR - numR * denL; // cross multiplies then subtracts for the numerator value
    denS = denL * denR; // multiply denominator for common denominator
    
    return numS, denS; // returns solutions numerator and denominator 
}

/******************************************************************
 * multiplication -- multiplies the operands and saves the solutions numerator and denominator
 *
 * Parameters: numL, numR, numS, denL, denR, denS
 * Modifies: none
 *
 * Pre condition -- none
 * 
 * Returns: the solutions numerator and denominator
 *******************************************************************/

double multiplication(int numL, int numR, int denL, int denR){
    numS = numL * numR; // multiply operands numerator for solution numerator
    denS = denL * denR; // multiply operands denominators for solution denominator
    
    return numS, denS; // returns solutions numerator and denominator 
}    

/******************************************************************
 * division -- divides the operands and saves the solutions numerator and denomimator
 *
 * Parameters: numL, numR, numS, denL, denR, denS
 * Modifies: none
 *
 * Pre condition -- none
 * 
 * Returns: the solutions numerator and denominator
 *******************************************************************/

double division(int numL, int numR, int denL, int denR){
    numS = numL * denR; // multiplies left operand numerator by rigth operand denominator (division is multiplying by the reciprocal)
    denS = denL * numR; // multiplies left operand denominator by right operand numerator

    return numS, denS; // returns solutions numerator and denominator 
}

/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifiers: cout, cin
 *            Prompts user for the following:
 *              - Which operator to use
 *              - left and right operands (fractions)
 * 
 * Pre Conditions: All inputs are numbers
 *
 * Returns: 0 
 *******************************************************************/

int main(){
    int choice; // creates operation choice variable as integer
    int numL; // creates left operands numerator variable as integer
    int denL; // creates left operands denominator variable as integer
    int numR; // creates right operands numerator variable as integer
    int denR; // creates left operands numerator variable as integer
    string op; // creates operation variable as string

    for(int i = 0; i < 5; i++){
        cout << "Rational number calculator" << endl; // tells shows user what this program is
        cout << "1) Add\n2) Subtract\n3) Multiply\n4) Divide\n5) Exit\n" << endl; // shows user which operations are available
        cout << "Please select an operation from above (1 - 5): " << endl; // prompts user to choose an operation
        cin >> choice; // saves the users choice of operation

        if(choice == 5){ // the user chose to exit
            cout << "Calculator terminated." << endl; // tells user the program is being terminated
            exit(0); // terminates program
        }

        cout << "Please enter the left operand numerator followed by denominator: " << endl; // ask user to input first fraction with the numerator and denominator seperated by a blank space
        cin >> numL >> denL; // saves the numerator and denominator
        cout << "Please enter the right operand numerator followed by denominator: " << endl; // ask user to input second fraction with the numerator and denominator seperated by a blank space
        cin >> numR >> denR; // saves the numerator and denominator

        if (choice == 1){ // user chose addition
            op = " + "; // sets the operation as +
            addition(numL, numR, denL, denR); // calls the addition function to do the math
        } else if (choice == 2){ // user chose subtraction
            op = " - "; // sets the operation as -
            subtraction(numL, numR, denL, denR); // calls the subtraction function to do the math
        } else if (choice == 3){ // user chose multiplication
            op = " * "; // sets the operation as * 
            multiplication(numL, numR, denL, denR); // calls the multiplication function to do the math
        } else if (choice == 4){  // user chose division
            op = " / "; // sets the operation as /
            division(numL, numR, denL, denR); // calls the addition division to do the math
        }

        rationalize(numL, numR, numS, denL, denR, denS); // calls the rationalize function to rationize the users operands

        cout << rnumL << "/" << rdenL << op << rnumR << "/" << rdenR << " = " << rnumS << "/" << rdenS << endl; // outputs the mathematical equation in reduced form

    }
}

/******************************************************************
 * $RCSfile: assign8.cpp$ 
 * $Revision$
 * $Oct 30, 2025$
 * $State$
 *
 * REVISION HISTORY
 *
 * $Log: assign8.cpp$
 * 
 * Revision 4 Oct 30, 2025
 * - Added for loop to pass new test case
 * 
 * Revision 3 Oct 24, 2025
 * - Figured out how to rationize numbers
 * - deleted vector and used return function
 * - added putting the negative sign into the numerator
 * - added washer.cpp style comments
 * 
 * Revision 2 Oct 22, 2025
 * - Created rationize function and to rationize without looking at the example given in class -- failed
 * - added parameters in the functions for easier variable movement
 * - used vector for variable storage
 * 
 * Revision 1 Oct 21, 2025
 * - Initial creation of variables and functions
 *      - Created main, addition, subtraction, multiplication, division
 * - Added all the main code asking for user inputs
 * - Added all the math for the operations
 ******************************************************************/

