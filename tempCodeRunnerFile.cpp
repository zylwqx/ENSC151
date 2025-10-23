#include <cmath>
#include <iostream>

using namespace std;

int num3;
int den3;
int ratio;


int main(){
    cin >> num3 >> den3;
    for (int i = 1; i < 100; i++){
        if (num3 % i == 0 && den3 % i == 0){
            ratio = i;
        }
    }
    cout << ratio;
    
}