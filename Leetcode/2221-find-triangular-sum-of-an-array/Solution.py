class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        val=1
        ans=nums[0]
        n=len(nums)
        for i in range(1,n):
            val=val*(n-i)
            val=val//i
            ans+=val*nums[i]
            ans=ans%10
        return ans