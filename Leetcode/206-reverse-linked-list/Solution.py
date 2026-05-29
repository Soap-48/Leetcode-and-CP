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

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.solve(None,head)
        