class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        l=-1
        ans=""
        val=1
        for i in range(1,len(s)):
            if s[i]=='(':
                val+=1
            else:
                val-=1
            if val==0:
                ans+=s[l+2:i]
                l=i
        return ans