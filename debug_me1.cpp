#include <iostream>
using namespace std;



int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

double division(double x, double y){
    return x / y;
}

int main() {
    ;
    int a = add(5, 4);
    int b = subtract(10, 4);
    double x = division(6, 5);

    cout << a << endl;
    cout << b << endl;
    cout << x << endl;
}