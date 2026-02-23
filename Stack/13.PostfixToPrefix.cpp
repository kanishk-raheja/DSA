#include<iostream>
#include<algorithm>
using namespace std;
struct Stack
{
    int size;
    string *arr;
    int top;
    Stack(int size)
    {
        this->size=size;
        arr = new string[size];
        top=-1;
    }
    void push(string element)
    {
        if(top == size -1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top]=element;
    }
    void display()
    {
        cout<<"Stack:"<<endl;
        for(int i=size-1;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
    bool empty()
    {
        return top==-1;
    }
    string peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return "";
        }
        return arr[top];
    }
    string pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return "";
        }
        return arr[top--];
    }
};
void PostFixToPreFix(string str)
{
    int n = str.length();
    int i=0;
    Stack s(n);
    string st = "";
    while(i<n)
    {
        char ch = str[i];
        if(isalnum(str[i]))
        {
            string operand(1,ch);
            s.push(operand);
        }
        else{
            string t1 = s.peek();
            s.pop();
            string t2 = s.peek();
            s.pop();
            st = str[i] + t2 + t1;
            s.push(st);
        }
        i++;
    }
    cout<<s.peek();
}
int main()
{
    string str;
    cin>>str;
    PostFixToPreFix(str);
}
