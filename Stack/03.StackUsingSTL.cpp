#include<iostream>
#include<stack>
using namespace std;
void display(stack<int> s)
{
    if (s.empty()) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "\nStack elements (top -> bottom):\n";
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop(); 
    }
}
void pop(stack<int> s)
{
    if(s.empty())
    {
        cout<<"Stack Underflow";
        return;
    }
    cout<<s.top()<<endl;
    s.pop();
}
int main()
{
    stack<int> s;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int element ;
        cin>>element;
        s.push(element);
    }
    display(s);
}
