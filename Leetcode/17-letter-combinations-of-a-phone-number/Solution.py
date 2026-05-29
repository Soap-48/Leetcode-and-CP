class Solution:
    d={
        '2':"abc",
        '3':"def",
        '4':"ghi",
        '5':"jkl",
        '6':"mno",
        '7':"pqrs",
        '8':"tuv",
        '9':"wxyz"
    }

    ans=[]

    def solve(self,dig,indice,str):
        if indice>=len(dig):
            self.ans.append(str)
        else:
            for i in self.d[dig[indice]]:
                self.solve(dig,indice+1,str+i)

    def letterCombinations(self, digits: str) -> List[str]:
        self.ans=[]
        self.solve(digits,0,'')
        return self.ans