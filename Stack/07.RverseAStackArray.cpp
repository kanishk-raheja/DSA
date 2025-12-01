#include<iostream>
using namespace std;
struct Stack
{
    int size;
    int *arr;
    int top;
    Stack(int size)
    {
        this->size=size;
        arr = new int[size];
        top=-1;
    }
    void push(int element)
    {
        if(top == size -1)
        {
            cout<<"Stack Overflow"<<endl;
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
    void reverse()
    {
        int i=0;
        int j=top;
        while(i<=j)
        {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    

};
int main()
{
    int n;
    cin>>n;
    Stack s(n);
    for(int i=0;i<n;i++)
    {
        int element ;
        cin>>element;
        s.push(element);
    }
    s.display();
    s.reverse();
    s.display();
}
