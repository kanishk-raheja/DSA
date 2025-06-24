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
void RotateRight(Node*& head, int steps)
{
    if(!head || !head->next || steps==0)
    {
        return;
    }
    Node* temp = head;
    int count = 1;
    while(temp->next)
    {
        temp=temp->next;
        count++;
    }
    temp->next=head;
    steps = steps%count;
    if(steps==0)
    {
        return;
    }
    Node* newTail = head;
    for(int i=1;i<count-steps;i++)
    {
        newTail=newTail->next;
    }
    head=newTail->next;
    newTail->next=nullptr;
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
    int steps;
    cout<<"Steps To Rotate:";
    cin>>steps;
    cout<<"Original List:";
    printList(head);
    RotateRight(head,steps);
    cout<<"After Rotating: ";
    printList(head);
}
