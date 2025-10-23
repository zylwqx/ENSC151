// example only
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(5) << 1 << setw(5) << 23 << setw(5) << 456 << '\n';
    cout << left << setw(5) << 1 << setw(5) << 23 << setw(5) << 456 << '\n';
    cout << setfill('.') << setw(6) << 42 << '\n';
    return 0;
}