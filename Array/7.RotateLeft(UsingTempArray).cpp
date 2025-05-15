#include<iostream>
using namespace std;

void RotateLeft(int arr[],int n,int k)
{
   
    int temp[n];
    cout<<"Shifted Array:";
    // Copy the elements from position k to n-1 into the beginning of temp
    for(int i=0;i<n-k;i++)
    {
        temp[i]=arr[k+i];
    }
    // Copy the first k elements of the original array to the end of temp
    for(int i=0;i<k;i++)
    {
        temp[n-k+i]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
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
