#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

struct Queue{
    Node* front;
    Node* rear;

    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int element){
        Node* newNode = new Node(element);

        if(front == nullptr)
            front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(front == nullptr)
            return;

        Node* temp = front;
        front = front->next;
        delete temp;

        if(front == nullptr)
            rear = nullptr;
    }

    void print(){
        Node* temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    int n;
    cin>>n;

    Queue q;

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        q.enqueue(element);
    }

    q.dequeue();
    q.print();
}#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

struct Queue{
    Node* front;
    Node* rear;

    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int element){
        Node* newNode = new Node(element);

        if(front == nullptr)
            front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(front == nullptr)
            return;

        Node* temp = front;
        front = front->next;
        delete temp;

        if(front == nullptr)
            rear = nullptr;
    }

    void print(){
        Node* temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    int n;
    cin>>n;

    Queue q;

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        q.enqueue(element);
    }

    q.dequeue();
    q.print();
}
