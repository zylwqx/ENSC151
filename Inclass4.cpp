#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int column = 0;

    cout << "   |  0  1  2  3  4  5  6  7  8  9" << endl;

    cout << "----------------------------------" << endl;

     while (column < 10){
        cout << setw(2) << column << " |";

        int row = 0;

        while (row < 10){
            cout << setw(3) << column * row;
            row++;
        }
        
        cout << endl;
        ++column;
    }
    return 0;
}