class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans=0
        for i in grid:
            for j in range(0,len(i)):
                if i[j]<0:
                    ans+=(len(i)-j)
                    break
        return ans