class Solution:
    def dsf(self, nums, k):
        count=0
        val=0
        l=0
        for r in range(len(nums)):
            count+=(nums[r]%2)
            if count>k:
                while count>k and l<r:
                    count-=nums[l]%2
                    l+=1
            if count<=k:
                val+=(r-l+1)
        return val

    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        return self.dsf(nums,k)-self.dsf(nums,k-1)