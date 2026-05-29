class Solution:
    def solve(self,r,c,board,visited,ind,word,ans):
        if not ans:
            if ind>=len(word):
                return True
            elif r>=len(board):
                return ans
            else:
                if visited[r][c]==0 and board[r][c]==word[ind]:
                    if ind==len(word)-1:
                        return True
                    if r>0:
                        visited[r][c]=1
                        ans=self.solve(r-1,c,board,visited,ind+1,word,ans)
                        visited[r][c]=0
                    if not ans and r<len(board)-1:
                        visited[r][c]=1
                        ans=self.solve(r+1,c,board,visited,ind+1,word,ans)
                        visited[r][c]=0
                    if not ans and c>0:
                        visited[r][c]=1
                        ans=self.solve(r,c-1,board,visited,ind+1,word,ans)
                        visited[r][c]=0
                    if not ans and c<len(board[0])-1:
                        visited[r][c]=1
                        ans=self.solve(r,c+1,board,visited,ind+1,word,ans)
                        visited[r][c]=0
                if not ans and ind==0:
                    c+=1
                    if c>=len(board[0]):
                        c=0
                        r+=1
                    ans=self.solve(r,c,board,visited,0,word,ans)    
                return ans
        return ans


    def exist(self, board: List[List[str]], word: str) -> bool:
        visited=[[0 for i in range(0,len(board[0]))] for j in range(0,len(board))]
        ans=False
        ans=self.solve(0,0,board,visited,0,word,ans)
        return ans