def max_wins(n, d, powers):
    powers.sort()
    
    left = 0          # weakest available player
    right = n - 1     # strongest available player
    wins = 0

    while left <= right:
        leader = powers[right]
        
        # Minimum players needed so that k * leader > d
        need = d // leader + 1

        if right - left + 1 >= need:
            # Form a team
            wins += 1
            left += need - 1
            right -= 1
        else:
            break

    return wins


# ---- Input / Output handling ----
n, d = map(int, input().split())
powers = list(map(int, input().split()))
print(max_wins(n, d, powers))
