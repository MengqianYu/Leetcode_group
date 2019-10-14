class Solution:
    def findMin(self, nums: List[int]) -> int:
        #这个题的点睛之笔在于当 nums[mid] == nums[high]的时候，保留nums[mid], 将nums[high]去除
        low, high = 0, len(nums)-1
        while low < high:
            mid = (low + high) >> 1
            if nums[mid] > nums[high]:
                low = mid + 1
            elif nums[mid] == nums[high]:
                high = high - 1
            else:
                high = mid
        return nums[low]