class Solution:
    ans=[]
    def solve(self,str,n,score):
        if n==0:
            if score==0:
                self.ans.append(str)
            else:
                self.solve(str+')',n,score-1)
        else:
            self.solve(str+'(',n-1,score+1)
            if score>0:
                self.solve(str+')',n,score-1)

    def generateParenthesis(self, n: int) -> List[str]:
        self.ans=[]
        self.solve('',n,0)
        return self.ans