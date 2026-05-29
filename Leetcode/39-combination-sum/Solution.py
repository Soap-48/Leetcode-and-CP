class Solution:
    ans=[]
    def solve(self,c,t,i,sum,v):
        if sum==t:
            self.ans.append(v[:])
        elif i>=len(c) or sum>t:
            return
        else:
            self.solve(c,t,i,sum+c[i],v+[c[i]])
            self.solve(c,t,i+1,sum,v)

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans=[]
        
        self.solve(candidates,target,0,0,[])
        return self.ans