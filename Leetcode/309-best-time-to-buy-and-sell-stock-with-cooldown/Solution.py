class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp=[[[-1e10 for __ in range(2)] for _ in range(2)] for i in range(len(prices)+1)]
        dp[0][0][0]=0
        for i in range(len(prices)):
            dp[i+1][0][0]=max(dp[i][0][1],dp[i][0][0])
            dp[i+1][0][1]=dp[i][1][0]+prices[i]
            dp[i+1][1][0]=max(dp[i][1][0],dp[i][0][0]-prices[i])
        ans=0
        ans=max(ans,dp[len(prices)][0][0],dp[len(prices)][0][1])
        return ans 