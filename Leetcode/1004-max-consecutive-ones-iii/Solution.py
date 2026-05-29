class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l=0
        c0=0
        ans=0
        for r in range(len(nums)):
            if nums[r]==0:
                c0+=1
            if c0>k:
                while nums[l]!=0:
                    l+=1
                l+=1
                c0-=1
            ans=max(ans,r-l+1)
        return ans