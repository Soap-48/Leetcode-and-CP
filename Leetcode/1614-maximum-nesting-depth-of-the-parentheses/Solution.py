class Solution:
    def maxDepth(self, s: str) -> int:
        d,ans=0,0
        for i in s:
            if i=='(':
                d+=1
                ans=max(ans,d)
            elif i==')':
                d-=1
        return ans        