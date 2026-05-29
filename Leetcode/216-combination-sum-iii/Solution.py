class Solution:
    ans=[]
    def solve(self,k,n,i,v,l,su):
        if su==n and l==k:
            self.ans.append(v[:])
        elif l>=k or i>9 or su>n:
            return
        else:
            self.solve(k,n,i+1,v,l,su)
            self.solve(k,n,i+1,v+[i],l+1,su+i)

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.ans=[]
        self.solve(k,n,1,[],0,0)
        return self.ans