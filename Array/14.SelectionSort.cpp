#include<iostream>
using namespace std;
void SelectionSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int SmallestIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[SmallestIndex])
            {
                SmallestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[SmallestIndex];
        arr[SmallestIndex]=temp;
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
    SelectionSort(arr,n);
    cout<<"After Sorting :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
