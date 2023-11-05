class Item:
    def __init__(self, profit, weight):
        self.profit = profit
        self.weight = weight

def fractional_knapsack(w, arr):
    arr.sort(key=lambda x: x.profit/x.weight, reverse=True)
    final_value = 0.0
    for item in arr:
        if w >= item.weight:
            final_value += item.profit
            w -= item.weight
        else:
            final_value += (w/item.weight) * item.profit
            break
    return final_value

if __name__ == "__main__":
    n = int(input("Enter number of items: "))
    arr = []
    for i in range(n):
        profit = int(input(f"Enter profit of item {i + 1}: "))
        weight = int(input(f"Enter weight of item {i + 1}: "))
        arr.append(Item(profit, weight))
    w = int(input("Enter capacity of knapsack: "))
    max_value = fractional_knapsack(w, arr)
    print(f"Maximum value in knapsack: {max_value}")
