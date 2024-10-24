#include <bits/stdc++.h> 
using namespace std; 

int topElement(stack<int>& s) { return s.top(); } 

int main() 
{ 

    stack<int> s; // creating a stack of integers 

    s.push(1); // This pushes 1 to the stack top 
    cout << topElement(s) 
        << endl; // Prints 1 since 1 is present at the 
                // stack top 

    s.push(2); // This pushes 2 to the stack top 
    cout << topElement(s) 
        << endl; // Prints 2 since 2 is present at the 
                // stack top 

    s.push(3); // This pushes 3 to the stack top 
    cout << topElement(s) 
        << endl; // Prints 3 since 3 is present at the 
                // stack top 
}
