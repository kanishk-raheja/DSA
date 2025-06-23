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
void DeleteAtTail(Node*& head)
{
    Node* temp =head;
    Node* prev=nullptr;
    if(head == nullptr)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    if(temp->next == nullptr)
    {

        delete(temp);
        temp = nullptr;
        return;
    }
    while(temp->next!=nullptr)
    {
        prev = temp;
        temp=temp->next;
    }
    prev->next =nullptr;
    delete(temp);
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
    cout<<"Original List:";
    printList(head);
    DeleteAtTail(head);
    cout<<"After Deleting: ";
    printList(head);
}
