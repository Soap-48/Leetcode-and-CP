class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        def solve(l,r):
            nonlocal nums
            a,b=0,0
            for i in range(0,r-l):
                c=a+nums[i+l]
                a=max(a,b)
                b=c
            return max(a,b)
        return max([nums[0],solve(0,n-1),solve(1,n)])
