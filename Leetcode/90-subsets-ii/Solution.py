class Solution:
    ans=[]
    def solve(self,c,i,v,n):
        if i>=n:
            self.ans.append(v[:])
        else:
            for j in range(i,n):
                if j>i and c[j]==c[j-1]:
                    continue
                self.solve(c,j+1,v+[c[j]],n)
            self.solve(c,n,v,n)
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.ans=[]
        self.solve(nums,0,[],len(nums))
        return self.ans
        