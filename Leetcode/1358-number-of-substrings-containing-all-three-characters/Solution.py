class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        c={'a':-1,'b':-1,'c':-1}
        ans=0
        n=len(s)
        for r in range(n-1,-1,-1):
            c[s[r]]=r
            if not -1 in list(c.values()):
                ans+=(n-max(list(c.values())))
        return ans