#include <iostream>
#include <cmath>
#include <myHeader.h>

using namespace std;

void calcRoot (double a, double b, double c, double &root1, double &root2);

int main(){
    double a, b, c, root1, root2;

    cout << "Enter coefficient a, b, c in that order" << endl;
    cin >> a >> b >> c;

    calcRoot (a, b, c, root1, root2);

    cout << "The roots of the quadratic formula is: " << root1 << " and " << root2;

    return 0;
}

void calcRoot (double a, double b, double c, double &root1, double &root2){

    root1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    root2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    return;
}