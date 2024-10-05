#include<iostream>
using namespace std;
void addelement(int* arr,int n,int element,int position)
{
    position --;

 for (int i = n - 1; i >= position; i--)
        //for shifting elemnts towards right that is element having index n is shifted at index n+1
        arr[i + 1] = arr[i];

    arr[position] = element;    
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Before insertion : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    int  position;
    cin>>position;
    int element;
    cin>>element;

    addelement(arr, n, element, position);
    n++;

    cout<<"After insertion : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

}
