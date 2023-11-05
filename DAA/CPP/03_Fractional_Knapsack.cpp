#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit;
    int weight;
};

bool compare(Item i1, Item i2) {
    return (double(i1.profit) / i1.weight) > (double(i2.profit) / i2.weight);
}

double fractional_knapsack(int w, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), compare);
    double final_value = 0.0;
    for (const Item& item : arr) {
        if (w >= item.weight) {
            final_value += item.profit;
            w -= item.weight;
        } else {
            final_value += (double(w) / item.weight) * item.profit;
            break;
        }
    }
    return final_value;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> arr[i].profit;
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> arr[i].weight;
    }
    int w;
    cout << "Enter capacity of knapsack: ";
    cin >> w;
    double max_value = fractional_knapsack(w, arr);
    cout << "Maximum value in knapsack: " << max_value << endl;
    return 0;
}
