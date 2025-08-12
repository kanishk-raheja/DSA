#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next ;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
void InsertAtTail(Node*& head,int data)
{
    Node* newNode = new Node(data);
    if(head==nullptr)
    {
        head=newNode;
        head->next=head;
        return;
    }
    Node* last = head;
    while(last->next != head)
    {
        last=last->next;
    }
    last->next=newNode;
    newNode->next=head;
    last = newNode;

}
void InserAfterElement(Node*& head ,int element ,int data)
{
    Node* newNode = new Node(data);
    Node* temp=head;
    while(temp!=nullptr && temp->data!=element)
    {
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Element not found"<<endl;
        return ;
    }
    newNode->next=temp->next;
    temp->next=newNode;  
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
        cout<<temp->data<<"->";
        temp=temp->next;
    } while (temp!=head);
    cout<<"Head"<<endl;
    
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
    int element,dataa;
    cout<<"Enter Element: ";
    cin>>element;
    cout<<"Enter Data: ";
    cin>>dataa;
    cout<<"Original List: ";
    PrintList(head);
    InserAfterElement(head,element,dataa);
    cout<<"List after insertion: ";
    PrintList(head);

}
