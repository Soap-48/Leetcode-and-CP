class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        else:
            a1=[0]*26
            for i in s:
                a1[ord(i)-ord('a')]+=1
            for i in t:
                a1[ord(i)-ord('a')]-=1
            for i in a1:
                if i!=0:
                    return False
            return True