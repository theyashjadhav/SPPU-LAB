def fibonacci_itr(n):
    steps = 0
    arr = [0, 1]
    for i in range(2, n):
        arr.append(arr[-1] + arr[-2])
        steps += 1
    print("fibonacci series itr:", *arr)
    print(f"No. of steps are itr: {steps}")

def fibonacci(n, result, steps):
    steps[0] += 1
    if n == 0:
        return 0
    if n == 1:
        return 1
    cur = fibonacci(n - 2, result, steps) + fibonacci(n - 1, result, steps)
    result[n] = cur
    return cur

def fibonacci_rec(n):
    steps = [0]
    result = [0] * n
    result[0] = 0
    result[1] = 1
    fibonacci(n-1, result, steps)

    print("\n\nfibonacci series rec:", *result )
    print(f"No. of steps are rec: {steps[0]}")

if __name__ == "__main__":
    n = int(input("Enter the number: "))

    fibonacci_itr(n)
    fibonacci_rec(n)
