def average_sleep_time():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    # Initial window sum
    window_sum = sum(a[:k])
    total = window_sum

    # Sliding window
    for i in range(k, n):
        window_sum += a[i]
        window_sum -= a[i - k]
        total += window_sum

    # Number of windows
    weeks = n - k + 1

    # Final average
    answer = total / weeks

    # Print with sufficient precision
    print(f"{answer:.10f}")


if __name__ == "__main__":
    average_sleep_time()
