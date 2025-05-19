#include<iostream>
using namespace std;
void InsertAtAnyPosition(int *arr,int n,int pos,int key)
{
    for(int i=n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=key;
}
int main()
{
    int n;
    cout<<"Total no. of Elements :";
    cin>>n;
    int arr[n];
    cout<<"Input Array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    int pos;
    cout<<"Position At which Element you want to insert:";
    cin>>pos;
    int key;
    cout<<"Element you want to Insert:";
    cin>>key;
    cout<<"After Insertion:";
    InsertAtAnyPosition(arr,n,pos,key);
    n++;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
