#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int target)
{
    // This is only used for sorted array 
    int low =0;
    int high= n-1;
    while(low<=high)
    {
        int mid = low +(high -low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid]<target)
        {
            low = mid+1;
        }
        else 
        {
            high =  mid -1;
        }
        return -1;
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
    int index =BinarySearch(arr,n,target);
    if(index==-1)
    {
      cout<<"Element not found":
    }
  else
    {
      cout<<"Element found at "<<index<<" index";//calling for Binarysearch function
    }
}
