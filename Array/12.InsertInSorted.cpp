#include<iostream>
using namespace std;
void InsertInSorted(int *arr,int n,int key)
{
    int i;
    for(i=n-1;(i>0 && arr[i]>key);i--)
    {
        arr[i+1]=arr[i];
    }
    arr[i+1]=key;
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
    int key;
    cout<<"Element you want to insert:";
    cin>>key;
    InsertInSorted(arr,n,key);
    n++;
    cout<<"After Insertion";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
