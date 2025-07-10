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
void DeleteKey(Node*& head , int key)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    if(head->data == key)
    {
        temp=head->next;
        if(temp!=nullptr)
        {
            temp->prev=nullptr;
        }
        delete head;
        head=temp;
        return;
    }
    Node* prev = nullptr;
    while(temp!= nullptr && temp->data != key)
    {
        prev = temp;
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Node Not Found"<<endl;
        return;
    }
    prev->next = temp->next;
    if(temp->next == nullptr)
    {
        prev->next= nullptr;
        delete temp;
        return;
    }
    temp->next->prev = prev;
    delete temp;
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
    int key,val;
    cout<<"Key To Delete: ";
    cin>>key;
    cout<<"Original List: ";
    printlist(head);
    DeleteKey(head,key);
    cout<<"Modified List: ";
    printlist(head);
}
