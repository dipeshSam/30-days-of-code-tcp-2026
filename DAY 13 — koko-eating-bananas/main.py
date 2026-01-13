import math
from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)      # We need max because list could be sorted in any direction.

        while left < right:
            mid = (left + right) // 2

            if not self.can_eat(piles, mid, h):
                left = mid + 1
            else:
                right = mid

        return left

    def can_eat(self, piles, speed, h):
        hours = 0

        for pile in piles:
            if speed >= pile:
                hours += 1
            else:
                hours += math.ceil(pile / speed)

        return hours <= h
    



if __name__ == "__main__":

    obj = Solution()

    print(obj.minEatingSpeed([3,6,7,11], h = 8))                # 4
    print(obj.minEatingSpeed([30,11,23,4,20], h = 5))           # 30
    print(obj.minEatingSpeed([30,11,23,4,20], h = 6))           # 23