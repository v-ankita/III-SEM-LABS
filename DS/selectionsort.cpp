//selection sort 

#include <iostream> 

using namespace std; 

  

void swap(int *a, int *b) 

{ 

    int temp = *a; 

    *a = *b; 

    *b = temp; 

} 

  

void selectionSort(int arr[], int n) 

{ 

    int min_idx; 

    int i, j; 

  

    for (i = 0; i < n - 1; i++) 

    { 

         

        min_idx = i;  

        for (j = i + 1; j < n; j++) 

        { 

            if (arr[j] < arr[min_idx]) 

                min_idx = j; 

        } 

        swap(&arr[min_idx], &arr[i]); 

    } 

} 

void printArray(int arr[], int n) 

{ 

    for (int i = 0; i < n; i++) 

    { 

        cout << arr[i] << " "; 

    } 

} 

int main() 

{ 

    int n; 

    cout << "Enter the number of elements of the array "; 

    cin >> n; 

    int arr[n]; 

    cout << "Enter the elements of the array " << endl; 

    for (int i = 0; i < n; i++) 

    { 

        cin >> arr[i]; 

    } 

  

    cout << "The entered array is : " << endl; 

    printArray(arr, n); 

  

    cout << "\nThe Sorted array is : "; 

    selectionSort(arr, n); 

    printArray(arr, n); 

    return 0; 

} 

 