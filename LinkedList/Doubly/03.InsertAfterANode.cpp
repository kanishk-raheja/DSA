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
void InsertAfterNode(Node*& head , int key , int data)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->data == key)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Node not Found";
        return;
    }

    Node* newNode= new Node(data);
    newNode->next=temp->next;
    newNode->prev= temp;
    temp->next->prev=newNode;
    temp->next=newNode;
}
void printlist(Node* head)
{
    cout<<"NULL";
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<"<-"<<temp->data<<"-> ";
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
    cout<<"Node to insert after: ";
    cin>>key;
    cout<<"New Node:" ;
    cin>>val;
    cout<<"Original List: ";
    printlist(head);
    InsertAfterNode(head , key , val);
    cout<<"Modified List: ";
    printlist(head);
}
