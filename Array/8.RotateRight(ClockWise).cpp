#include<iostream>
using namespace std;
void RotateRight(int arr[],int n,int k)
{
    cout<<"Shifted Array:";
    for(int i=0;i<k;i++)
    {
        int last=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[0]=last;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
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
    int k;
    cout<<"No. of places you want to shift:";
    cin>>k;
    RotateRight(arr,n,k);
}
