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
void DeleteAtKey(Node*& head,int key)
{
    Node* temp=head;
    Node* prev;
    if(head==nullptr)
    {
        cout<<"List is Empty: "<<endl;
        return;
    }
    if(key==head->data)
    {
        head=head->next;
        delete(temp);
        return;
    }
    while(temp!=nullptr && temp->data!=key)
    {
        prev = temp;
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Element not found"<<endl;
        
    }
    prev->next=temp->next;
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
    int key;
    cout<<"Enter Key You Want To Delete: ";
    cin>>key;
    cout<<"Original List:";
    printList(head);
    // DeleteAtPosition(head,pos);
    DeleteAtKey(head,key);
    cout<<"After Deleting: ";
    printList(head);
}
