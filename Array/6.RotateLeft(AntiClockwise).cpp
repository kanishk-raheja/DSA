#include<iostream>
using namespace std;

void RotateLeft(int arr[],int n,int k)
{
    // Loop for making shift 1
    for(int i=0;i<k;i++)
    {
        int first=arr[0];
        // loop for shifting elements
        for(int j=0;j<n-1;j++)
        {
           arr[j]=arr[j+1];

        }
        arr[n-1]=first;
    }
    cout<<"Shifted Array:";
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
    RotateLeft(arr,n,k);

}
