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
// void InserAtTail(Node*& head,Node*& tail,int value)
// {
//     Node* newNode = new Node(value);
//     if(head==nullptr)
//     {
//         head=newNode;
//         tail=newNode;
//     }
//     else
//     {
//         tail->next=newNode;
//         tail=newNode;
//     }
// }
// void InsertAtTail(Node*& head, int val) {
//     Node* newNode = new Node(val);
//     if (head == nullptr) {
//         head = newNode;
//         return;
//     }

//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }
// void InsertAtFront(Node*& head,int value)
// {
//     Node* newNode = new Node(value);
//     if(head==nullptr)
//     {
//         head=newNode;
//     }
//     else{
//         newNode->next=head;
//         head=newNode;
//     }
// }
// void InsertAtBack(Node*& head,int value)
// {
//     Node* newNode = new Node(value);
//     if(head==nullptr)
//     {
//         head = newNode;
//         return;
//     }
//     Node* temp = head;
//     while(temp->next!=nullptr)
//     {
//         temp=temp->next;
//     }
//     temp->next=newNode;
// }
// void InsertAfter(Node*& head,int key,int value)
// {
//     Node* temp = head;
//     while(temp!=nullptr)
//     {
//         if(temp->data==key)
//         {
//             break;
//         }
//         temp=temp->next;
//     }
//     if(temp==nullptr)
//     {
//         cout<<"Node Not Found"<<endl;
//         return;
//     }
//     Node* newNode=new Node(value);
//     newNode->next=temp->next;
//     temp->next=newNode;
// }
// void InsertBefore(Node*& head,int key , int value)
// {
//     if(head==nullptr)
//     {
//         cout<<"List Is Empty"<<endl;
//         return ;
//     }
//     if(head->data==key)
//     {
//         Node* newNode = new Node(value);
//         newNode->next= head;
//         head=newNode;
//         return;
//     }
//     Node* pre=nullptr;
//     Node* curr= head;
//     while(curr!=nullptr && curr->data!=key)
//     {
//         pre=curr;
//         curr=curr->next;
//     }
//     if(curr==nullptr)
//     {
//         cout<<"Element Not Found"<<endl;
//         return;
//     }
//     Node* newNode = new Node(value);
//     newNode->next=curr;
//     pre->next=newNode;
// }
void InsertAtPos(Node*& head,int pos,int value)
{
    if(pos<1)
    {
        return ;
    }
    if(pos==1)
    {
        Node* newNode = new Node(value);
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* curr = head;
    for(int i=1;(i<pos-1 && curr!=nullptr);i++)
    {
        curr=curr->next;
    }
    if(curr==nullptr)
    {
        cout<<"Position not Found "<<endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next=curr->next;
    curr->next=newNode;

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
        // InsertAtTail(head,value);
    }
    // cout<<"Enter New Node You Want to Insert at Front:";
    // int NewValue;
    // cin>>NewValue;
    int element , NewValue;
    // cout<<"Enter the Element after which you want to insert:";
    // cout<<"Enter the Element before which you want to insert:";
    // cin>>element;
    int pos;
    cout<<"Position At Which You Want To Insert Node:";
    cin>>pos;
    cout<<"Element you want to insert:";
    cin>>NewValue;
    cout<<"Before Insertion:";
    printList(head);
    // InsertAtFront(head,NewValue);
    // InsertAtBack(head,NewValue);
    // InsertAfter(head,element,NewValue);
    // InsertBefore(head,element,NewValue);
    InsertAtPos(head,pos,NewValue);
    cout<<"After Insertion:";
    printList(head);
}
