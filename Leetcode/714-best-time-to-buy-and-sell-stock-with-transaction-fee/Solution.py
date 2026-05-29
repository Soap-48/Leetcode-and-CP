class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp=[[-1e10 for _ in range(2)] for i in range(len(prices)+1)]
        dp[0][0]=0
        for i in range(len(prices)):
            dp[i+1][0]=max(dp[i][1]+prices[i],dp[i][0])
            dp[i+1][1]=max(dp[i][1],dp[i][0]-prices[i]-fee)
        return max(dp[len(prices)])