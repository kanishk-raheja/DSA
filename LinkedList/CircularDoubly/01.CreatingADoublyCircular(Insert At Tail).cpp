#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next ;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
void InsertAtTail(Node*& head,int data)
{
    Node* newNode = new Node(data);
    if(head==nullptr)
    {
        head=newNode;
        head->next=head;
        head->prev=head;
        return;
    }
    Node* last = head;
    while(last->next != head)
    {
        last=last->next;
    }
    last->next=newNode;
    newNode->prev=last;
    newNode->next=head;
    head->prev =newNode;
    last = newNode;

}
void PrintList(Node* head)
{
    if(head==nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    do
    {
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    } while (temp!=head);
    cout<<"Head";
    
}
int main()
{
    int n;
    cout<<"No. of elements: ";
    cin>>n;
    Node* head = nullptr;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        InsertAtTail(head,data);
    }
    cout<<"Original List: ";
    PrintList(head);
}
