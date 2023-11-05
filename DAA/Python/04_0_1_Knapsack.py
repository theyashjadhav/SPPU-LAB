def knapSack(W, wt, val, n):
    dp = [[0 for x in range(W+1)] for x in range(n+1)]

    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif wt[i-1] <= w:
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]

    selected_items = []
    i, w = n, W
    while i > 0 and w > 0:
        if dp[i][w] != dp[i-1][w]:
            selected_items.append(i)
            w -= wt[i-1]
            i -= 1
        else:
            i -= 1

    print("Selected Items:")
    for item in reversed(selected_items):
        print(f"Item {item} (Value: {val[item-1]}, Weight: {wt[item-1]})")

    return dp[n][W]

n = int(input("Enter number of items: "))
val = list(map(int, input("Enter values of items: ").split()))
wt = list(map(int, input("Enter weights of items: ").split()))
W = int(input("Enter capacity of knapsack: "))

max_value = knapSack(W, wt, val, n)
print(f"Maximum value in knapsack: {max_value}")
