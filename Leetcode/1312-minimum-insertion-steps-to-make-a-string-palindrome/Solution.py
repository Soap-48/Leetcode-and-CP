class Solution: 
    def minInsertions(self, s: str) -> int:
        n=len(s)
        dp=[[-1 for _ in range(n)] for __ in range(n)]
        for i in range(n):
            dp[i][i]=0
        def solve(s,i,j):
            nonlocal dp
            if dp[i][j]!=-1:
                return dp[i][j]
            else:
                if j-i>=2 and s[i]==s[j]:
                    dp[i][j]=solve(s,i+1,j-1)
                    return dp[i][j]
                elif s[i]==s[j]:
                    dp[i][j]=0
                    return 0
                else:
                    #ss=s[0:i]+s[j]+s[i:]
                    val1=solve(s,i,j-1)
                    #se=s[0:j+1]+s[i]+s[j+1:]
                    val2=solve(s,i+1,j)
                    dp[i][j]=1+min(val1,val2)
                    return dp[i][j]
        return solve(s,0,n-1)
