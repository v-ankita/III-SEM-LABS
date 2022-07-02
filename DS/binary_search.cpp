#include <iostream> 

using namespace std; 

  

int main() 

{ 

    int n; 

    int mid, low, high; 

  

    cout << "Enter the length of array: "; 

    cin >> n; 

    int arr[n]; 

    cout << "Enter the sorted array\n"; 

    for (int i = 0; i < n; i++) 

        cin >> arr[i]; 

  

    int key; 

    cout << "Enter element to search: "; 

    cin >> key; 

  

    low = 0; 

    high = n - 1; 

  

    do 

    { 

        mid = (low + high) / 2; 

        if (key < arr[mid])  

            high = mid - 1; 

        else if (key > arr[mid]) 

            low = mid + 1; 

    } while (key != arr[mid] && low <= high); 

  

    if (key == arr[mid]) 

    { 

        cout << "Element present at index " << mid << endl; 

    } 

    else 

    { 

        cout << "Element not present\n"; 

    } 

    return 0; 

} 