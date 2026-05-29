class Solution:
    def romanToInt(self, s: str) -> int:
        lookup={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        ans,max=0,0
        for i in s[::-1]:
            val=lookup[i]
            if val>=max:
                max=val
                ans+=val
            else:
                ans-=val
        return ans