#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 1;
    int *p_a = &a;
    cout << p_a << endl; // this gives the hexadecimal number of the address 
    cout << *p_a<<endl; // gives the value of the address
    *p_a = 5;
    // this channges the value at the address
    cout << *p_a<< endl;

    // changing the address 
    int *changed_address = p_a+1;
    cout << p_a+1 << endl;
    cout << *changed_address<<endl;// this the stuff present at that point
    // the unchanged p_a
    cout << *p_a << endl;

    // Double pointer
    



}