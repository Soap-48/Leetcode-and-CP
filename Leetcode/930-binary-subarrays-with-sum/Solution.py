class Solution:
    def sumatleastchuchu(self, nums, goal):
        val=0
        sum=0
        l=0
        for r in range(len(nums)):
            sum+=nums[r]
            if sum>goal:
                while sum>goal and l<=r:
                    sum-=nums[l]
                    l+=1
            val+=(r-l+1)
        return val

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        if goal>0:
            return self.sumatleastchuchu(nums,goal)-self.sumatleastchuchu(nums,goal-1)
        else:
            return self.sumatleastchuchu(nums,0)