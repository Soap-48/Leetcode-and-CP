class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n=len(prices)
        dp=[[[-1e10 for ___ in range(2)] for __ in range(k+1)] for _ in range(n+1)]
        dp[0][0][0]=0
        for i in range(n):
            for j in range(k+1):
                dp[i+1][j][0]=max(dp[i][j][0],dp[i][j][1]+prices[i])
            for j in range(k):
                dp[i+1][j+1][1]=max(dp[i][j+1][1],dp[i][j][0]-prices[i])
        ans=0
        for i in range(k+1):
            ans=max(ans,dp[n][i][0],dp[n][i][1])
        return ans