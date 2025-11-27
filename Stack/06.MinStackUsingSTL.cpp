#include <iostream>
#include <stack>
using namespace std;

stack<int> st;      
stack<int> minst;   

void push(int element)
{
    st.push(element);

    if (minst.empty() || element <= minst.top())
        minst.push(element);
    else
        minst.push(minst.top());   
}

void display()
{
    if (st.empty())
    {
        cout << "Stack is Empty";
        return;
    }

    cout << "Normal Stack :"<<endl;
    stack<int> temp1 = st;
    while (!temp1.empty())
    {
        cout << temp1.top() <<endl;
        temp1.pop();
    }

    cout << "Min Stack :"<<endl;
    stack<int> temp2 = minst;
    while (!temp2.empty())
    {
        cout << temp2.top() <<endl;
        temp2.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        push(element);
    }

    display();

    return 0;
}
