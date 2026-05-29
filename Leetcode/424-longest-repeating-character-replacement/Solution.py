class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans=0
        for i in range(ord('A'),ord('Z')+1):
            j=chr(i)
            count=0
            l=0
            for r in range(len(s)):
                if s[r]!=j:
                    count+=1
                    if count>k:
                        while count>k:
                            if s[l]!=j:
                                count-=1
                            l+=1
                ans=max(ans,r-l+1)
        return ans