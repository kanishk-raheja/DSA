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
void DeleteAtPosition(Node*& head,int pos)
{
    Node* temp=head;
    Node* prev;
    if(pos==1)
    {
        head= head->next;
        delete(temp);
        return;
    }
    for(int i=1;i!=pos;i++)
    {
        prev =temp;
        temp=temp->next;
    }
    if(temp!=nullptr)
    {
        prev->next=temp->next;
        delete(temp);
    }
    else{
        cout<<"Position Not Found"<<endl;
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
    int pos;
    cout<<"Enter Position of Node You Want to Delete:";
    cin>>pos;
    cout<<"Original List:";
    printList(head);
    DeleteAtPosition(head,pos);
    cout<<"After Deleting: ";
    printList(head);
}
