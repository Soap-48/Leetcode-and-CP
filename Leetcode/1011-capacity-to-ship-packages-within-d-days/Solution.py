class Solution:
    def possible(self, weights: List[int], days: int,k) -> bool:
        val=0
        sum=0
        for i in weights:
            sum+=i
            if sum==k:
                sum=0
                val+=1
            elif sum>k:
                sum=i
                val+=1
        if sum>0:
            val+=1
        if val>days:
            return False
        else:
            return True

    def shipWithinDays(self, weights: List[int], days: int) -> int:
        n=len(weights)
        l=max(weights)
        r=len(weights)*l
        ans=0
        while l<=r:
            m=(l+r)//2
            flag=self.possible(weights,days,m)
            if flag:
                ans=m
                r=m-1
            else:
                l=m+1
        return ans
        