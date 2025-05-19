#include<iostream>
using namespace std;
void DeleteElement(int arr[],int n,int key)
{
    int pos;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            pos = i;
        }
    }
    for(int i=pos;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    
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
    cout<<"Enter The Element you want to Delete:";
    cin>>key;
    DeleteElement(arr,n,key);
    n--;
    cout<<"After Deleting:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
