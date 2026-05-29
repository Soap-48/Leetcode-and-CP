class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans=strs[0]
        for i in range(1,len(strs)):
            j=0
            n1,n2=len(ans),len(strs[i])
            n=min(n1,n2)
            while j<n:
                if ans[j]!=strs[i][j]:
                    break
                j+=1
            ans=ans[0:j]
        return ans