from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        # Step 1: Count frequency
        freq = Counter(s)

        # Step 2: Create buckets (index = frequency)
        buckets = [[] for _ in range(len(s) + 1)]
        for ch, f in freq.items():
            buckets[f].append(ch)

        # Step 3: Build result from high frequency to low
        result = []
        for f in range(len(buckets) - 1, 0, -1):
            for ch in buckets[f]:
                result.append(ch * f)

        return "".join(result)


def main():
    sol = Solution()

    test_cases = [
        "tree",
        "cccaaa",
        "Aabb",
        "bbbaaacccddd"
    ]

    for s in test_cases:
        print(f"Input: {s} → Output: {sol.frequencySort(s)}")


if __name__ == "__main__":
    main()
