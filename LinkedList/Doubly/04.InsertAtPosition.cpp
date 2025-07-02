#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
void InsertAtTail(Node*& head , Node*& tail, int data)
{
    Node* newNode = new Node(data);
    if(head==nullptr)
    {
        head=tail=newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}
void InsertAtPos(Node*& head ,int pos , int data)
{
    if(pos==1)
    {
        Node* newNode = new Node(data);
        newNode->next=head;
        head->prev=newNode;
        newNode->prev=nullptr;
        head= newNode;
        return;
    }
    Node* temp = head;
    for(int i=1;(i<pos -1 && temp!=nullptr);i++)
    {
        count++;
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Position not found"<<endl;
        return;
    }
    
    Node* newNode = new Node(data);
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=nullptr)
    {
        temp->next->prev=newNode;
    }
    temp->next=newNode;
}
void printlist(Node* head)
{
    cout<<"NULL";
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<"<- "<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int n;
    cout<<"Total No. Of Nodes: ";
    cin>>n;
    Node* head = nullptr;
    Node* tail = nullptr;
    int data;
    for(int i = 0;i<n;i++)
    {
        cin>>data;
        InsertAtTail(head,tail,data);
    }
    int val;
    cout<<"Position To Insert: ";
    int pos;
    cin>>pos;
    cout<<"New Node:" ;
    cin>>val;
    cout<<"Original List: ";
    printlist(head);
    InsertAtPos(head,pos,val);
    cout<<"Modified List: ";
    printlist(head);
}
