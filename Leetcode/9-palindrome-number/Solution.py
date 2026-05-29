class Solution:
    def isPalindrome(self, x: int) -> bool:
        s=str(x)
        ss=s[::-1]
        return s==ss
        