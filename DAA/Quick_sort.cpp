#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r, bool f, int &steps) {
    int iPivot = (f ? r : (l + rand() % (r - l + 1)));
    swap(arr[iPivot], arr[r]);
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            steps++; 
        }
    }
    swap(arr[i + 1], arr[r]);
    steps++;
    return (i + 1);
}

void quicksort(int arr[], int l, int r, bool f, int &steps) {
    if (l < r) {
        int iPivot = partition(arr, l, r, f, steps);
        cout << "Pivot: " << arr[iPivot] << " ";
        cout << "Sorted Array: ";
        for (int i = l; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        quicksort(arr, l, iPivot - 1, f, steps);
        quicksort(arr, iPivot + 1, r, f, steps);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    int* arr1 = new int[n];
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr1[i] = arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    
    int steps = 0; 
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(arr, 0, n - 1, 0, steps);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
    cout << "Sorted array with pivot as the random element: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<"\nNumber of steps: " << steps << "\n\n";
    
    steps = 0; 
    start = std::chrono::high_resolution_clock::now();
    quicksort(arr1, 0, n - 1, 1, steps);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
    cout << "Sorted array with rightmost pivot: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\nNumber of steps: " << steps << "\n";
    
    return 0;
}
