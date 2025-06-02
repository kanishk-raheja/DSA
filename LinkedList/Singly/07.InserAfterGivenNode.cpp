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
void InsertAfter(Node*& head,int key,int value)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->data==key)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Node Not Found"<<endl;
        return;
    }
    Node* newNode=new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
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
    int element , NewValue;
    cout<<"Enter the Element after which you want to insert:";
    cin>>element;
    cout<<"Element you want to insert:";
    cin>>NewValue;
    cout<<"Before Insertion:";
    printList(head);
    InsertAfter(head,element,NewValue);
    cout<<"After Insertion:";
    printList(head);
}
