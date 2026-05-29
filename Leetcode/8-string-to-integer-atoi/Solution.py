class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.strip()
        if len(s)<=0:
            return 0
        sign=1
        if s[0]=='-':
            sign=-1
        i=0
        if s[0]=='-' or s[0]=='+':
            i+=1
        ans=0
        for n in range(i,len(s)):
            if s[n].isdigit():
                ans=ans*10+int(s[n])
            else:
                break
        ans=ans*sign
        max=(2**31)-1
        min=-(2**31)
        if ans>max:
            ans=max
        elif ans<min:
            ans=min
        return ans