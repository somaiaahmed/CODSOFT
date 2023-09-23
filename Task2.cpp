#include <bits/stdc++.h>
using namespace std;


int main() {

    double x,y;
    char opertion;

    cout<<"SIMPLE CALCULATOR! \n";

    cout<<"Enter The First Number: ";
    cin>>x;

    cout<<"Enter The Second Number: ";
    cin>>y;

    cout<<"Choose an operation (+, -, *, /):";
    cin>>opertion;

    double res=0;

    if(opertion=='+')
       res=x+y;
    else  if(opertion=='-')
        res=x-y;
    else  if(opertion=='*')
        res=x*y;
    else  if(opertion=='/') {
        if(y==0){
            cout<<"Error! Division By zero.\n";
            return 0;
        }
        res = x / y;
    }
    else {
        cout << "Operation doesn't exist, Please choose a valid operation\n";
    return 0;
    }
    cout<<"Result = "<<res<<endl;
}
