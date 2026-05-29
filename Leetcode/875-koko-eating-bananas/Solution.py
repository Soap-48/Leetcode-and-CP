import math as m

def check(piles: List[int],k:int,h:int) -> bool:
    val=0
    for i in piles:
        val+=m.ceil(i/k)
    if val<=h:
        return True
    else:
        return False

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        n=len(piles)
        l,r=1,max(piles)
        ans=r
        while l<=r:
            m=(l+r)//2
            flag=check(piles,m,h)
            if flag:
                ans=m
                r=m-1
            else:
                l=m+1
        return ans