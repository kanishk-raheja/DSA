#include<iostream>
using namespace std;

struct Queue{
    int *arr;
    int capacity;
    int front;
    int rear;

    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    void enqueue(int element){
        if(rear == capacity - 1)
            return;

        if(front == -1)
            front = 0;

        arr[++rear] = element;
    }

    void print(){
        if(front == -1 || front > rear){
            cout<<"Queue Empty";
            return;
        }

        for(int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
    }
};

int main(){
    int n, element;
    cin>>n;

    Queue q(n);
    for(int i=0;i<n;i++)
    {
      cin>>element;
      q.enqueue(element);
    }
    q.print();
}
