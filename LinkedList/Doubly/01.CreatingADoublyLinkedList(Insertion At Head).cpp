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
void InsertAtHead(Node*& head , Node*& tail, int data)
{
    Node* newNode = new Node(data);
    if(head == nullptr )
    {
        head = tail = newNode;
    }
    else{
        newNode -> next = head ;
        head ->prev = newNode;
        head = newNode;
    }
}
void printlist(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" <-> ";
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
        InsertAtHead(head,tail,data);
    }
    printlist(head);

}
