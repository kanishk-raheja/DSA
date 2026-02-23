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
void PrefixToInfix(string str)
{
    reverse(str.begin(),str.end());
    int n = str.length();
    int i=0;
    string st="";
    Stack s(n);
    while(i<n)
    {
        char ch = str[i];
        if((str[i]>='a' && str[i]<='z') ||
           (str[i]>='A' && str[i]<='Z') ||
           (str[i]>='0' && str[i]<='9')
        )
        {
            string operand(1,ch);
            s.push(operand);
        }
        else{
            string t1 = s.peek();
            s.pop();
            string t2 = s.peek();
            s.pop();
            st = "(" + t1 + str[i] + t2 +")";
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
    PrefixToInfix(str);
}
