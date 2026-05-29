# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        l,r=head,head
        while r!=None and r.next!=None:
            l=l.next
            r=r.next.next
        return l
        