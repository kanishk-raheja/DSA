#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
struct Stack
{
    Node* top;
    Stack()
    {
        top = NULL;
    }
    void push(int element)
    {
        Node* newNode = new Node(element);
        newNode->next=top;
        top = newNode;
    }
    void display()
    {
        cout<<"Stack:  "<<endl;
        Node* temp = top;
        while(temp!=nullptr)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    int pop()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow";
            return -1;
        }
        Node* temp = top;
        int val = temp->data;
        top=temp->next;
        delete temp;
        return val;
    }
    void InsertAtBottom(int t)
    {
        if (top==NULL)
        {
            push(t);
            return;
        }
        int x=pop();
        InsertAtBottom(t);
        push(x);
    }
    void reverse()
    {
        if(top==NULL){
            return;
        }
        int t = pop();
        reverse();
        InsertAtBottom(t);

    }

};
int main()
{
    int n; 
    cin>>n;
    Stack s;
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        s.push(element);
    }
    s.display();
    s.reverse();
    s.display();
}
