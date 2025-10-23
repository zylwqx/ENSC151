#include <iostream>
#include <iomanip>

int main() {
    using namespace std;

    cout << "   |  0  1  2  3  4  5  6  7  8  9" << endl; // First Row

    cout << "----------------------------------" << endl; // Separator

    for (int column = 0; column < 10; ++column) { 
        cout << setw(2) << column << " |"; // write number then separator
        for (int row = 0; row < 10; ++row) { 
            cout << setw(3) << column * row; // do calculations and print body
        }
        cout << endl;
    }
    return 0;
}