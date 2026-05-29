class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        q=[]
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    q.append((i,j))
        ans=-1
        
        while q:
            ans+=1
            siz=len(q)
            for i in range(siz):
                x,y=q.pop(0)
                if x>=1 and grid[x-1][y]==1:
                    grid[x-1][y]=2
                    q.append((x-1,y))
                if y>=1 and grid[x][y-1]==1:
                    grid[x][y-1]=2
                    q.append((x,y-1))
                if x+1<m and grid[x+1][y]==1:
                    grid[x+1][y]=2
                    q.append((x+1,y))
                if y+1<n and grid[x][y+1]==1:
                    grid[x][y+1]=2
                    q.append((x,y+1))
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    return -1
        return max(ans,0)
                
