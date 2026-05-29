class Solution:
    ans=[]
    def solve(self,num,ind,target,v,val,last):
        if ind>=len(num):
            if val==target:
                self.ans.append(v[:])
        else:
            for i in range(ind+1,len(num)+1):
                if i-ind>=2 and num[ind]=='0':
                    break
                j=int(num[ind:i])
                self.solve(num,i,target,v+'+'+num[ind:i],val+j,j)
                self.solve(num,i,target,v+'-'+num[ind:i],val-j,-j)
                self.solve(num,i,target,v+'*'+num[ind:i],val+last*(int(num[ind:i])-1),last*int(num[ind:i]))
    
    def addOperators(self, num: str, target: int) -> List[str]:
        self.ans=[]
        for i in range(1,len(num)+1):
            if i>=2 and num[0]=='0':
                break
            self.solve(num,i,target,num[0:i],int(num[0:i]),int(num[0:i]))
        return self.ans    