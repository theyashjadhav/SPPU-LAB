import random
import time

# Deterministic Partition for Quick Sort
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Randomized Partition for Quick Sort
def random_partition(arr, low, high):
    random_index = random.randint(low, high)
    arr[random_index], arr[high] = arr[high], arr[random_index]
    return partition(arr, low, high)

# Deterministic Quick Sort
def deterministic_quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        deterministic_quick_sort(arr, low, pi - 1)
        deterministic_quick_sort(arr, pi + 1, high)

# Randomized Quick Sort
def randomized_quick_sort(arr, low, high):
    if low < high:
        pi = random_partition(arr, low, high)
        randomized_quick_sort(arr, low, pi - 1)
        randomized_quick_sort(arr, pi + 1, high)

if __name__ == "__main__":
    SIZE = 100000
    arr = [random.randint(1, 10000) for _ in range(SIZE)]

    # Clone array for both variants
    deterministic_arr = arr[:]
    randomized_arr = arr[:]

    # Measure time for deterministic quicksort
    start_deterministic = time.time()
    deterministic_quick_sort(deterministic_arr, 0, SIZE - 1)
    end_deterministic = time.time()
    deterministic_duration = (end_deterministic - start_deterministic) * 1000  # Convert to milliseconds

    # Measure time for randomized quicksort
    start_randomized = time.time()
    randomized_quick_sort(randomized_arr, 0, SIZE - 1)
    end_randomized = time.time()
    randomized_duration = (end_randomized - start_randomized) * 1000  # Convert to milliseconds

    print(f"Deterministic Quick Sort took {deterministic_duration} milliseconds.")
    print(f"Randomized Quick Sort took {randomized_duration} milliseconds.")
