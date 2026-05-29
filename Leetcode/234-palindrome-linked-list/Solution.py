# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def solve(self,prev,curr):
        if curr!=None:
            temp=curr.next
            curr.next=prev
            return self.solve(curr,temp)
        else:
            return prev

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        l,r=head,head
        while r!=None and r.next!=None:
            l=l.next
            r=r.next.next
        if r!=None:
            l=l.next
        r=head
        l=self.solve(None,l)
        while l!=None:
            if l.val!=r.val:
                return False
            l=l.next
            r=r.next
        return True
