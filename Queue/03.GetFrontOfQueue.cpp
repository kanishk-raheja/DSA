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
        if(front == -1)
            front = 0;
        arr[++rear] = element;
    }

    int getfront(){
        if(front == -1 || front > rear)
            return -1;
        return arr[front];
    }
};

int main(){
    int n;
    cin>>n;

    Queue q(n);

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        q.enqueue(element);
    }

    cout<<q.getfront();
}
