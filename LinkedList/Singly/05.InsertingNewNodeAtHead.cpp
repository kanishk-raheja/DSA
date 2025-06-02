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
void InsertAtHead(Node*& head,int value)
{
    Node* newNode = new Node(value);
    newNode -> next = head;
    head = newNode;

}
void InsertAtFront(Node*& head,int value)
{
    Node* newNode = new Node(value);
    if(head==nullptr)
    {
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data<< " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    cout<<"Enter No. Of Nodes:";
    cin>>n;
    int value;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Value for Node "<<i+1<<":";
        cin>>value;
        InsertAtHead(head,value);
    }
    cout<<"Enter New Node You Want to Insert at Front:";
    int NewValue;
    cin>>NewValue;
    cout<<"Before Insertion:";
    printList(head);
    InsertAtFront(head,NewValue);
    cout<<"After Insertion:";
    printList(head);
}
