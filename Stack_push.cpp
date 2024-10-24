#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

    stack<int> s; // creating a stack of integers 

    s.push(1); // This pushes 1 to the stack top 

    s.push(2); // This pushes 2 to the stack top 

    s.push(3); // This pushes 3 to the stack top 

    s.push(4); // This pushes 4 to the stack top 

    s.push(5); // This pushes 5 to the stack top 

    // printing the stack 

    while (!s.empty()) { 
        cout << s.top() << " "; 
        s.pop(); 
    } 

    // The above loop prints "5 4 3 2 1" 
}
