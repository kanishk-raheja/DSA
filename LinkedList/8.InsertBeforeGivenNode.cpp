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
void InsertBefore(Node*& head,int key , int value)
{
    if(head==nullptr)
    {
        cout<<"List Is Empty"<<endl;
        return ;
    }
    if(head->data==key)
    {
        Node* newNode = new Node(value);
        newNode->next= head;
        head=newNode;
        return;
    }
    Node* pre=nullptr;
    Node* curr= head;
    while(curr!=nullptr && curr->data!=key)
    {
        pre=curr;
        curr=curr->next;
    }
    if(curr==nullptr)
    {
        cout<<"Element Not Found"<<endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next=curr;
    pre->next=newNode;
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
    cout<<"Enter the Element before which you want to insert:";
    cin>>element;
    cout<<"Element you want to insert:";
    cin>>NewValue;
    cout<<"Before Insertion:";
    printList(head);
    InsertBefore(head,element,NewValue);
    cout<<"After Insertion:";
    printList(head);
}
