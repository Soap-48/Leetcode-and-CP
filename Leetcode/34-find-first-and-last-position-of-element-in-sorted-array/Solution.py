class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        l,r=0,n-1
        while l<=r:
            m=(l+r)//2
            if nums[m]==target:
                t=m
                while t<n and nums[t]==target:
                    t+=1
                b=t-1
                t=m
                while t>=0 and nums[t]==target:
                    t-=1
                return [t+1,b]
            elif nums[m]>target:
                r=m-1
            else:
                l=m+1
            
        return [-1,-1]