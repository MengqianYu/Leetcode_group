class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 对于每一位的数来说，它就代表了所在LIS的最后一位，因此，只要num[i]
        # 大过它，就可以加一
        if not nums:
            return 0
        
        n = len(nums)
        dp = [0] * n
        
        for i in range(n):
            maxLength = 1
            for j in range(i):
                if nums[i] > nums[j] and maxLength < dp[j] + 1:
                    maxLength = dp[j] + 1
            dp[i] = maxLength
            
        return max(dp) 