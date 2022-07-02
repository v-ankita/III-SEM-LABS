#include <iostream> 

using namespace std; 

  

void LinearSearch(int arr[], int n, int num) 

{ 

    bool flag = true; 

    for (int i = 0; i < n; i++) 

    { 

        if (arr[i] == num) 

        { 

            cout << "\nElement " << num << " is present at index " << i+1 <<endl; 

            flag = true; 

            break; 

        } 

        else 

            flag = false; 

    } 

    if (flag = false) 

        cout << "\nElement " << num << " is not present in the array" << endl; 

} 

  

int main() 

{ 

    int n, num; 

    cout << "Enter the number of elements of the array "; 

    cin >> n; 

  

    int arr[n]; 

    cout << "Enter the elements of the array " << endl; 

    for (int i = 0; i < n; i++) 

    { 

        cin >> arr[i]; 

    } 

  

    cout << "Enter the element to search"; 

    cin >> num; 

  

    LinearSearch(arr, n, num); 

  

    return 0; 

} 

 