class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        ketamine=image[sr][sc]
        q=[(sr,sc)]
        m,n=len(image),len(image[0])
        while q:
            x,y=q.pop(0)
            if x>=1 and image[x-1][y]==ketamine:
                image[x-1][y]=-1
                q.append((x-1,y))
            if y>=1 and image[x][y-1]==ketamine:
                image[x][y-1]=-1
                q.append((x,y-1))
            if x+1<m and image[x+1][y]==ketamine:
                image[x+1][y]=-1
                q.append((x+1,y))
            if y+1<n and image[x][y+1]==ketamine:
                image[x][y+1]=-1
                q.append((x,y+1))
        image[sr][sc]=color
        for i in range(m):
            for j in range(n):
                if image[i][j]==-1:
                    image[i][j]=color
        return image