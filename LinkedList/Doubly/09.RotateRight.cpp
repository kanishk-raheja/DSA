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
void RotateRight(Node*& head, int steps) 
{
    if(!head || !head->next || steps==0)
    {
        return;
    }
    Node * temp = head;
    int count =1;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    steps=steps%count;
    temp->next=head;
    head->prev=temp;
    if(steps==0)
    {
        head->prev = nullptr;
        temp->next = nullptr;
        return;
    }
    Node* curr = head;
    for(int i=1;i<=count-steps;i++)
    {
        curr=curr->next;
    }
    Node* newTail= curr->prev;
    newTail->next=nullptr;
    curr->prev=nullptr;
    head=curr;
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
    int steps;
    cout<<"Enter Number Of Steps: ";
    cin>>steps;
    cout<<"Original List: ";
    printlist(head);
    RotateRight(head,steps);
    cout<<"Modified List: ";
    printlist(head);
}
