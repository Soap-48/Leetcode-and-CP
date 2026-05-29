class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        ans=0
        n=len(isConnected)
        vis=[0]*n
        def dfs(r):
            nonlocal isConnected,vis,n
            vis[r]=1
            for i in range(n):
                if isConnected[r][i] and vis[i]==0:
                    dfs(i)
        for i in range(n):
            if vis[i]==0:
                ans+=1
                dfs(i)
        return ans