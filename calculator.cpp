#include <iostream>
#include <cmath>
using namespace std;
int main (){
    double a, b, res;
    char ch;
    cout << "Enter Your Arithmatic Operator: ";
    cin >> ch;
    cout << "Enter Your Numbers: ";
    cin >> a >> b;
    
    switch (ch) {
        case '+':
        res = a+b;
        break;
        case '-':
        res = a-b;
        break;
        case '*':
        res = a*b;
        break;
        case '/':
        /*if (a<b){
            int temp = a;
            a=b;
            b=temp;
            res = a/b;
        }
        else{res = a/b;}*/
        res = a/b;
        break;
        default:
        cout<< "Invalid Operator";
        break;
    }
    cout << res;
    return 0;
}