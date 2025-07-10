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
void DeleteAtTail(Node*& head )
{
    if(head==nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->next==nullptr)
    {
        Node* temp = head;
        head = nullptr;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* curr = nullptr;
    while(temp->next!=nullptr)
    {
        curr=temp;
        temp=temp->next;
    }
    curr->next=nullptr;
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
    cout<<"Original List: ";
    printlist(head);
    DeleteAtTail(head);
    cout<<"Modified List: ";
    printlist(head);
}
