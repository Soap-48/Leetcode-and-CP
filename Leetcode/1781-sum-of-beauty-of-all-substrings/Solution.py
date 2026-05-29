class Solution:
    def beautySum(self, s: str) -> int:
        n=len(s)
        ans=0
        for i in range(0,len(s)):
            freq=[0]*26
            for j in range(i,len(s)):
                freq[ord(s[j])-ord('a')]+=1
                mini=100000
                maxi=-1
                for k in freq:
                    if k!=0:
                        mini=min(mini,k)
                        maxi=max(maxi,k)
                ans+=(maxi-mini)
        return ans
