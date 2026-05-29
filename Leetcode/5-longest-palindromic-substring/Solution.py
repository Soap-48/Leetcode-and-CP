class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans=1
        ss=s[0]
        for i in range(0,len(s)-1):
            if s[i]==s[i+1]:
                siz=0
                l,r=i,i+1
                while l>=0 and r<len(s) and s[l]==s[r]:
                    siz+=2
                    l-=1
                    r+=1
                if siz>ans:
                    ans=siz
                    ss=s[max(0,l+1):(min(len(s),r))]
            if i>0 and s[i-1]==s[i+1]:
                siz=1
                l,r=i-1,i+1
                while l>=0 and r<len(s) and s[l]==s[r]:
                    siz+=2
                    l-=1
                    r+=1
                if siz>ans:
                    ans=siz
                    ss=s[max(0,l+1):(min(len(s),r))]
        return ss