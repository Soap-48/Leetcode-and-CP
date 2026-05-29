class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min=prices[0]
        ans=0
        for i in prices:
            if i<min:
                min=i
            ans=max(ans,i-min)
        return ans