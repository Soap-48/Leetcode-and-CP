class Solution:
    def possible(self,nums,threshold,k) -> bool:
        val=0
        for i in nums:
            val+=ceil(i/k)
        if val<=threshold:
            return True
        else:
            return False

    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        n=len(nums)
        l,r=1,max(nums)
        ans=-1
        while l<=r:
            m=(l+r)//2
            flag=self.possible(nums,threshold,m)
            if flag:
                ans=m
                r=m-1
            else:
                l=m+1
        return ans