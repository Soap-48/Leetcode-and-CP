class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n=len(matrix)
        dp=[matrix[0][i] for i in range(len(matrix[0]))]
        for i in range(1,n):
            t=[matrix[i][j] for j in range(len(matrix[0]))]
            for j in range(n):
                x=dp[j]
                if j>0:
                    x=min(x,dp[j-1])
                if j<n-1:
                    x=min(x,dp[j+1])
                t[j]+=x
            dp=t
        return min(dp)