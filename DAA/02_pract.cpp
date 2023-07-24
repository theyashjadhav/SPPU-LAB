#include <bits/stdc++.h>
using namespace std;

// Function to perform Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> numbers;
    int num;
    
    ifstream inputFile("input.txt");
    
    if (!inputFile) {
        cout << "Error opening file!";
        return 1;
    }
    
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    
    inputFile.close();
    
    // Applying Merge Sort
    mergeSort(numbers, 0, numbers.size() - 1);
    
    // Applying Insertion Sort
    insertionSort(numbers);
    
    ofstream outputFile("output.txt");
    
    if (!outputFile) {
        cout << "Error creating output file!";
        return 1;
    }
    
    for (int num : numbers) {
        outputFile << num << " ";
    }
    
    outputFile.close();
    
    cout << "Sorting completed and saved to output.txt\n";
    
    return 0;
}
