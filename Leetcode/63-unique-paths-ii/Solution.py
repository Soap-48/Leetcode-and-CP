class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0]==1:
            return 0
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        dp=[[0 for i in range(0,n)] for j in range(0,m)]
        dp[0][0]=1
        for i in range(0,m):
            for j in range(0,n):
                if obstacleGrid[i][j]==1:
                    dp[i][j]=0
                elif i>0 or j>0:
                    l=dp[i-1][j] if i>0 else 0
                    r=dp[i][j-1] if j>0 else 0
                    dp[i][j]=l+r
        return dp[m-1][n-1]
