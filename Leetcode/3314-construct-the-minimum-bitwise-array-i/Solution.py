class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        def solve(n):
            if n==2:
                return -1
            else:
                pos=0
                temp=n
                while temp>0:
                    if temp%2==0:
                        break
                    pos+=1
                    temp=temp//2
                return(n-(2**(pos-1)))
        ans=[solve(i) for i in nums]
        return ans
        