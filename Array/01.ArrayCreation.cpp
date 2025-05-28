#include<iostream>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    int arr[n];
    cout<<"Input Array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Output Array";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
