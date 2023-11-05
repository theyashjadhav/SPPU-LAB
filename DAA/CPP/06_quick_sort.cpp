#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Deterministic Partition for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized Partition for Quick Sort
int randomPartition(vector<int>& arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    const int SIZE = 100000;
    vector<int> arr(SIZE);

    // Generate random integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    // Clone array for both variants
    vector<int> deterministicArr = arr;
    vector<int> randomizedArr = arr;

    // Measure time for deterministic quicksort
    auto startDeterministic = high_resolution_clock::now();
    deterministicQuickSort(deterministicArr, 0, SIZE - 1);
    auto stopDeterministic = high_resolution_clock::now();
    auto deterministicDuration = duration_cast<milliseconds>(stopDeterministic - startDeterministic);

    // Measure time for randomized quicksort
    auto startRandomized = high_resolution_clock::now();
    randomizedQuickSort(randomizedArr, 0, SIZE - 1);
    auto stopRandomized = high_resolution_clock::now();
    auto randomizedDuration = duration_cast<milliseconds>(stopRandomized - startRandomized);

    cout << "Deterministic Quick Sort took " << deterministicDuration.count() << " milliseconds." << endl;
    cout << "Randomized Quick Sort took " << randomizedDuration.count() << " milliseconds." << endl;

    return 0;
}
