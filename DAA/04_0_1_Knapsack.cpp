#include <iostream>
#include <vector>

using namespace std;

void printSelectedItems(vector<vector<int>>& dp, vector<int>& val, vector<int>& wt, int n, int W) {
    int i = n, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << " (Value: " << val[i - 1] << ", Weight: " << wt[i - 1] << ")\n";
            w -= wt[i - 1];
            i--;
        } else {
            i--;
        }
    }
}


int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Selected Items:\n";
    printSelectedItems(dp, val, wt, n, W);

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n);
    vector<int> wt(n);

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int W;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int max_value = knapSack(W, wt, val, n);
    cout << "Maximum value in knapsack: " << max_value << endl;

    return 0;
}
