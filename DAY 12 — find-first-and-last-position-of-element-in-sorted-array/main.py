class Solution(object):
    def findLeft(self, nums: list[int], target: int):
        low, high = 0, len(nums) - 1
        pos = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                pos = mid
                high = mid - 1  # move left
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return pos

    def findRight(self, nums: list[int], target: int):
        low, high = 0, len(nums) - 1
        pos = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                pos = mid
                low = mid + 1  # move right
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return pos


    def searchRange(self, nums: list[int], target: int):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        return [self.findLeft(nums, target), self.findRight(nums, target)]


    
        
if __name__ == "__main__":
    obj = Solution()

    indices = obj.searchRange([5, 7, 7, 8, 8, 8, 10, 4], 7)

    print(indices)
        