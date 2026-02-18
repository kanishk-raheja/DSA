#include<iostream>
#include<algorithm>
using namespace std;
struct Stack
{
    int size;
    char *arr;
    int top;
    Stack(int size)
    {
        this->size=size;
        arr = new char[size];
        top=-1;
    }
    void push(int element)
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
    char peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return -1;
        }
        return arr[top];
    }
    char pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return -1;
        }
        return arr[top--];
    }
};
int priority(char op)
{
    if(op=='^')
    {
        return 3; 
    }
    if(op=='/'||op=='*')
    {
        return 2;
    }
    if(op=='+'||op=='-')
    {
        return 1;
    }
    return 0;

}
void InfixToPrefix(string str)
{
    string result="";
    int n=str.length(),i=0;
    Stack s(n);
    reverse(str.begin(),str.end());
    cout<<"Reversed String"<<str<<endl;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            str[i]=')';
        }
        else if(str[i]==')')
        {
            str[i]='(';
        }
    }
    cout<<"Correct String To Prefix"<<str<<endl;
    while(i<n)
    {
        if((str[i]>='a' && str[i]<='z')||
           (str[i]>='A' && str[i]<='Z')||
           (str[i]>='0' && str[i]<='9'))
        {
            result = result+str[i];
        }
        else if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(!s.empty() && s.peek()!='(')
            {
                result= result+ s.peek();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(
                !s.empty() && 
                priority(s.peek())>priority(str[i]) 
            )
            {
                result += s.peek();
                s.pop();
            }
            s.push(str[i]);
        }
        i++;
    }
    while(!s.empty())
    {
        result+=s.peek();
        s.pop();
    }
    reverse(result.begin(),result.end());
    cout<<result;

}
int main()
{
    string str;
    cin>>str;
    InfixToPrefix(str);
}
