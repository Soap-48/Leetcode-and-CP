class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        ans={}
        li=[]
        for i in range(0,len(s)):
            if ans.get(s[i])!=t[i]:
                if ans.get(s[i])==None:
                    if t[i] in li:
                        return False
                    else:
                        ans[s[i]]=t[i]
                        li.append(t[i])
                else:
                    return False
        return True
        