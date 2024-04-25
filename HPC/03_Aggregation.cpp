#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int parallelMin(const vector<int>& arr) {
    int min_val = arr[0];

    #pragma omp parallel for reduction(min:min_val)
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    return min_val;
}

int parallelMax(const vector<int>& arr) {
    int max_val = arr[0];

    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    return max_val;
}

int parallelSum(const vector<int>& arr) {
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }

    return sum;
}

double parallelAverage(const vector<int>& arr) {
    int sum = parallelSum(arr);
    double average = static_cast<double>(sum) / arr.size();
    return average;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9, 3, 6, 4, 7};

    int min_val = parallelMin(arr);
    cout << "Minimum value: " << min_val << endl;

    int max_val = parallelMax(arr);
    cout << "Maximum value: " << max_val << endl;

    int sum = parallelSum(arr);
    cout << "Sum of values: " << sum << endl;

    double average = parallelAverage(arr);
    cout << "Average of values: " << average << endl;

    return 0;
}
