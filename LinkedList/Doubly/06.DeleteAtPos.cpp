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
void DeleteAtPos(Node*& head, int pos)
{
    if(head==nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if(pos<=0)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(pos==1)
    {
        Node* temp =  head;
        head = head ->next;
        if(head!=nullptr)
        {
            head->prev = nullptr;
        }
        else{
            head =nullptr;
        }
        delete temp;
        return;
    }
    Node * temp = head;
    Node* curr = nullptr;
    for(int i=1;(i<pos && temp!=nullptr);i++)
    {
        curr=temp;
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    curr->next=temp->next;
    if(temp->next!=nullptr)
    {
        temp->next->prev = curr;
    }
    delete temp;
}
void printlist(Node* head)
{
    if(head==nullptr)
    {
        cout<<"List Is Empty"<<endl;
        return ;
    }
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
    int key,val;
    int pos ;
    cout<<"Index To Delete: ";
    cin>>pos;
    cout<<"Original List: ";
    printlist(head);
    DeleteAtPos(head,pos);
    cout<<"Modified List: ";
    printlist(head);
}
