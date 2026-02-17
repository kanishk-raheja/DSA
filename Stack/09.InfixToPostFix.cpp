#include<iostream>
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
    int peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return -1;
        }
        return arr[top];
    }
    int pop()
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
void InfixToPostfix(string str)
{
   string result="";
   Stack s(str.length());
   int i=0,n=str.length();
   while(i<n)
   {
        if((str[i]>='a'&& str[i]<='z')|| (str[i]>='A'&& str[i]<='Z') || (str[i]>='0'&&str[i]<='9'))
        {
            result+=str[i];
        }
        else if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(!s.empty() && s.peek()!='(')
            {
                result+=s.top;
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
    result+=s.pop();
   }
cout << result;
}
int main()
{
    string str;
    cin>>str;
    InfixToPostfix(str);
}
