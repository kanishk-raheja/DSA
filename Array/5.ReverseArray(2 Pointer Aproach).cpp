#include<iostream>
using namespace std;

void ReverseArray(int arr[],int n)
{
    int low = 0;//Pointer 1
    int high = n-1;//Pointer 2
    cout<<"Reversed Array:";
    while (low<high)
    {
        int temp = arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
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

    ReverseArray(arr,n);
}
