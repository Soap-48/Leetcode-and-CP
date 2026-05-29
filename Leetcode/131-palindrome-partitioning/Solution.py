class Solution:
    ans=[]
    def pal(self,s):
        i=0
        j=len(s)-1
        while i<j:
            if s[i]!=s[j]:
                return False
            i+=1
            j-=1
        return True

    def solve(self,s,ind,v):
        if ind>=len(s):
            self.ans.append(v[:])
        else:
            for k in range(ind+1,len(s)+1):
                if self.pal(s[ind:k]):
                    self.solve(s,k,v+[s[ind:k]])

    def partition(self, s: str) -> List[List[str]]:
        self.ans=[]
        self.solve(s,0,[])
        return self.ans