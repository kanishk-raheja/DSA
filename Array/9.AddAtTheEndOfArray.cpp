#include<iostream>
using namespace std;
int InsertAtEnd(int *arr,int n,int key)
{
    arr[n]=key;
    return n+1;
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
    cout<<"Element you want to inser At End:";
    cin>>key;
    n=InsertAtEnd(arr,n,key);
    cout<<"After Insertion:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
