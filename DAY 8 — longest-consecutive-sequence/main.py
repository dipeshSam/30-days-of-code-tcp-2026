
# It might be so lengthy in C/C++, so I chose Python.

def longestConsecutive(nums):
    num_set = set(nums)
    longest = 0

    for num in num_set:
        # Check if num is the start of a sequence
        if num - 1 not in num_set:
            current = num
            length = 1

            while current + 1 in num_set:
                current += 1
                length += 1

            longest = max(longest, length)

    return longest

if __name__ == "__main__":
    print(longestConsecutive([1,0,1,2]))
