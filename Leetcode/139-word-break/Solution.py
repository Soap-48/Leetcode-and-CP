class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp=[False]*(len(s)+1)
        dp[0]=True
        maxl=0
        for i in wordDict:
            maxl=max(maxl,len(i))
        for i in range(1,len(s)+1):
            for j in range(1,maxl+1):
                if i-j>=0:
                    if dp[i-j] and s[i-j:i] in wordDict:
                        dp[i]=True
                        break
        return dp[len(s)]