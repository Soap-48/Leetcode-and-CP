class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        dp=[[grid[j][i] for i in range(0,n)] for j in range(0,m)]
        for i in range(0,m):
            for j in range(0,n):
                if i>0 or j>0:
                    l=dp[i-1][j] if i>0 else 100000000000
                    r=dp[i][j-1] if j>0 else 10000000000
                    dp[i][j]+=min(l,r)
        return dp[m-1][n-1]