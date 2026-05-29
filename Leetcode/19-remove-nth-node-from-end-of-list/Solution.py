# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head==None or head.next==None:
            return None
        delay=n
        l,r=head,head
        while delay>0:
            r=r.next
            delay-=1
        prev=None
        if r==None:
            return head.next
        while r!=None:
            r=r.next
            prev=l
            l=l.next
        prev.next=l.next
        return head
        
        