#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int* arr, int n) {
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n); 
    
    bubbleSort(arr, n);
    //selectionSort(arr, n);  // If you want to use selectionSort, uncomment this line

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
