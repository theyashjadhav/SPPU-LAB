#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

void parallelBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;

    while (swapped) {
        swapped = false;

        #pragma omp parallel for shared(arr, swapped)
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {

                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    }
}


void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

void sequentialMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        sequentialMergeSort(arr, left, middle);

        sequentialMergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void parallelMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                parallelMergeSort(arr, left, middle);
            }

            #pragma omp section
            {
                parallelMergeSort(arr, middle + 1, right);
            }
        }

        merge(arr, left, middle, right);
    }
}

int main() {

    srand(time(nullptr));
    const int SIZE = 10000;

    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 10000; 
    }

    vector<int> seqBubbleSortArr = arr;
    auto start = high_resolution_clock::now();
    bubbleSort(seqBubbleSortArr);
    auto stop = high_resolution_clock::now();
    auto seqBubbleSortTime = duration_cast<milliseconds>(stop - start);

    vector<int> parBubbleSortArr = arr;
    start = high_resolution_clock::now();
    parallelBubbleSort(parBubbleSortArr);
    stop = high_resolution_clock::now();
    auto parBubbleSortTime = duration_cast<milliseconds>(stop - start);

    vector<int> seqMergeSortArr = arr;
    start = high_resolution_clock::now();
    sequentialMergeSort(seqMergeSortArr, 0, SIZE - 1);
    stop = high_resolution_clock::now();
    auto seqMergeSortTime = duration_cast<milliseconds>(stop - start);

    vector<int> parMergeSortArr = arr;
    start = high_resolution_clock::now();
    parallelMergeSort(parMergeSortArr, 0, SIZE - 1);
    stop = high_resolution_clock::now();
    auto parMergeSortTime = duration_cast<milliseconds>(stop - start);

    cout << "Sequential Bubble Sort Time: " << seqBubbleSortTime.count() << " ms" << endl;
    cout << "Parallel Bubble Sort Time: " << parBubbleSortTime.count() << " ms" << endl;
    cout << "Sequential Merge Sort Time: " << seqMergeSortTime.count() << " ms" << endl;
    cout << "Parallel Merge Sort Time: " << parMergeSortTime.count() << " ms" << endl;

    return 0;
}
