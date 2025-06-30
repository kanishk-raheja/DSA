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
// void InsertAtHead(Node*& head , Node*& tail, int data)
// {
//     Node* newNode = new Node(data);
//     if(head == nullptr )
//     {
//         head = tail = newNode;
//     }
//     else{
//         //Node* temp = head;
//         newNode -> next = head ;
//         head ->prev = newNode;
//         head = newNode;
//     }
// }
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
void printlist(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" <-> ";
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
        // InsertAtHead(head,tail,data);
        InsertAtTail(head,tail,data);
    }
    printlist(head);
    

}
