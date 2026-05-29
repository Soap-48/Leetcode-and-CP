class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        ans=1
        for i in range(2,m+n-1):
            ans*=i
        for i in range(2,n):
            ans//=i
        for i in range(2,m):
            ans//=i
        return ans
