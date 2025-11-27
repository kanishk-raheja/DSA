#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int element)
    {
        this->data=element;
        this->next=nullptr;
    }
};
struct Stack
{
    Node* stack;
    Node* minstack;
    Stack()
    {
        stack=nullptr;
        minstack=nullptr;
    }
    void push (int element)
    {
        Node* newNode = new Node(element);
        newNode->next=stack;
        stack=newNode;

        if(minstack == nullptr || element<=minstack->data)
        {
            Node* minNode = new Node(element);
            minNode->next = minstack;
            minstack = minNode;
        }
        else
        {
            element = minstack->data;
            Node* minNode = new Node(element);
            minNode->next = minstack;
            minstack = minNode;
        }
    }
    void display()
    {
        if(stack==nullptr || minstack == nullptr)
        {
            cout<<"Stack is Empty";
            return;
        }
        Node* temp1 = stack;
        Node* temp2 = minstack;
        cout<<"Normal Stack: "<<endl;
        while(temp1!=nullptr)
        {
            cout<<temp1->data<<endl;
            temp1=temp1->next;
        }
        cout<<"Min Stack: "<<endl;
        while(temp2!=nullptr)
        {
            cout<<temp2->data<<endl;
            temp2=temp2->next;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    Stack s;
    for(int i=0;i<n;i++)
    {
        int element ;
        cin>>element;
        s.push(element);
    }
    s.display();
}
