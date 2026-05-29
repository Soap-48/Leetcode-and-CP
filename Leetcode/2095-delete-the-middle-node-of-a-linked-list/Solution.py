# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return None
        l,r=head,head
        prev=None
        while r!=None and r.next!=None:
            prev=l
            l=l.next
            r=r.next.next
        prev.next=l.next
        return head
        
        