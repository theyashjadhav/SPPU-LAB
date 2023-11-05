#include <bits/stdc++.h>
using namespace std;

void fibonacci_itr(int n)
{
    int steps = 0;
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        steps++;
    }
    cout << "fibonacci series itr: ";
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
    cout << "No.of steps are itr: " << steps << endl;
}

int fibonacci(int n, int result[], int &steps)
{
    steps++;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int cur = fibonacci(n - 2, result, steps) + fibonacci(n - 1, result, steps);
    result[n] = cur;
    return cur;
}

void fibonacci_rec(int n)
{
    int steps = 0;
    int result[n];
    result[0] = 0;
    result[1] = 1;
    fibonacci(n, result, steps);

    cout << "\n\nfibonacci series rec: ";
    for (auto ele : result)
    {
        cout << ele << " ";
    }
    cout << "\n";
    cout << "No.of steps are rec: " << steps << endl;
}

int main()
{
    int n;
    cout << "Enter the no. : ";
    cin >> n;

    fibonacci_itr(n);
    fibonacci_rec(n);

    return 0;
}
