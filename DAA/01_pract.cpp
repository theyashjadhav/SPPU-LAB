#include <bits/stdc++.h>
using namespace std;
#define N 3
void fibonacci_s(int n)
{
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << "fibonacci series : ";
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
}



void factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    cout << "factorial : " << ans;
    cout << "\n";
}

void bubble_sort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "bubb le sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int binary_search(int arr[], int l, int r, int target)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            return binary_search(arr, l, (mid - 1), target);
        }

        return binary_search(arr, (mid + 1), r, target);
    }
    return -1;
}

void mat_multiplyer(int mat1[][N], int mat2[][N], int n)
{
    int ans[N][N];
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a = 0;
            for (int k = 0; k < n; k++)
            {
                a += mat1[i][k] * mat2[k][j];
            }

            ans[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    fibonacci_s(10);
    factorial(6);
    int a[] = {10, 2, 5, 27, 50, 200};
    int n = 6;
    bubble_sort(a, n);
    int f = binary_search(a, 0, n - 1, 27);
    if (f == -1)
    {
        cout << "not in arr \n";
    }
    else
    {
        cout << "element found ata index : " << f << endl;
    }

    int m1[][N] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

    int m2[][N] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

    mat_multiplyer(m1, m2, 3);
    return 0;
}