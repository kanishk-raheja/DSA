#include<iostream>
using namespace std;
int LinearSearch(int arr[],int n,int target)
{
    
    for(int i=0;i<n;i++)
    {
        if(target==arr[i])
        {
            return i;
        }
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
    
    int target;
    cout<<"Target to acheive:";
    cin>>target;
    //calling for linear search function
    cout<<"Element found at "<<LinearSearch(arr,n,target)<<" index;
}
