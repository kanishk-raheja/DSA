#include<iostream>
using namespace std;

void ReverseArray(int arr[],int n)
{
    int temp[n];
    cout<<"Reversed Array";
    for(int i=0;i<n;i++)
    {
        temp[i]=arr[n-1-i];//Storing the values in temp array
        cout<<temp[i]<<" ";
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
    
    ReverseArray(arr,n);
}
