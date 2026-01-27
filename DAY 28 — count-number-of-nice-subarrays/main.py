class Solution(object):
    def numberOfSubarrays(self, nums, k):
        count = {0: 1}   # prefix_sum -> frequency
        prefix_sum = 0
        result = 0

        for num in nums:
            prefix_sum += num % 2   # odd -> 1, even -> 0

            if prefix_sum - k in count:
                result += count[prefix_sum - k]

            count[prefix_sum] = count.get(prefix_sum, 0) + 1

        return result


def main():
    sol = Solution()

    # Test Case 1
    nums = [1, 1, 2, 1, 1]
    k = 3
    print("Test Case 1 Output:", sol.numberOfSubarrays(nums, k))  # Expected: 2

    # Test Case 2
    nums = [2, 4, 6]
    k = 1
    print("Test Case 2 Output:", sol.numberOfSubarrays(nums, k))  # Expected: 0

    # Test Case 3
    nums = [2, 2, 2, 1, 2, 2, 1, 2, 2, 2]
    k = 2
    print("Test Case 3 Output:", sol.numberOfSubarrays(nums, k))  # Expected: 16


if __name__ == "__main__":
    main()
