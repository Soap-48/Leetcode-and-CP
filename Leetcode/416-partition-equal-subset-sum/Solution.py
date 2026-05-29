class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n=len(nums)
        val=sum(nums)
        if(val&1):
            return False
        dp=[0 for _ in range(1+(val//2))]
        dp[0]=1
        for i in range(n):
            for j in range(val//2,nums[i]-1,-1):
                if dp[j-nums[i]]:
                    dp[j]=1
        if dp[val//2]:
            return True
        else:
            return False