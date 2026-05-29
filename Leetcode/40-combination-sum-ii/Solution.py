class Solution:
    ans=[]
    def solve(self,c,t,i,sum,v):
        if sum==t:
            self.ans.append(v[:])
        elif i>=len(c) or sum>t:
            return
        else:
            for j in range(i,len(c)):
                if j>i and c[j]==c[j-1]:
                    continue
                self.solve(c,t,j+1,sum+c[j],v+[c[j]])
            
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.ans=[]
        self.solve(candidates,target,0,0,[])
        return self.ans