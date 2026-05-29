class Solution:
    def intToRoman(self, num: int) -> str:
        ans=''
        lookup={1:"I",5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M',9:'IX',4:'IV',40:"XL",90:'XC',400:"CD",900:"CM"}
        s=str(num)
        po=len(s)
        po-=1
        po=pow(10,po)
        for i in s:
            dig=int(i)
            val=dig*po
            if dig==4 or dig==9:
                ans+=lookup[val]
            else:
                while val>0:
                    if val>=1000:
                        val-=1000
                        ans+="M"
                    elif val>=500:
                        val-=500
                        ans+="D"
                    elif val>=100:
                        val-=100
                        ans+="C"
                    elif val>=50:
                        val-=50
                        ans+="L"
                    elif val>=10:
                        val-=10
                        ans+="X"
                    elif val>=5:
                        val-=5
                        ans+="V"
                    else:
                        val-=1
                        ans+="I"
            po=po/10
        return ans