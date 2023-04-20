#include<bits/stdc++.h>
using namespace std;

int main(){
    // declare them with the string var name
    string s,c,d;
    cin >> s;
    cin >> c;
    //adding
    cout << s+c << endl;

    //equating
    if (c==s){
        cout << "Equal";
    }
    else{
        cout << "NEqual";
    }

    // Accessing a particular character and changing
    c[0]='a';
    cout << endl <<c[0];
    // these are characters so u cant reassign them using double qoutes (! c[0]="a")

    // getting the size 
    cout << endl << c.size()<<endl;
    
    
    // if u want the same input with the spaces and other things use getline function
    // getline() reads from the input, there is a newline character left in the input stream, so it doesn't read your c-string. Use cin. ignore() before calling getline() .
    //The cin before one ends on slashes or the new line so the getline does not ignore the slashes or the newline so we use ignore function.
    cin.ignore();
    getline(cin,d);
    cout << d;

    //  to append a character in the last of the string use push_back
    s.push_back(s[0]);
    cout << endl << s;
}