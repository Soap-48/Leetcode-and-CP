# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        node=head
        a=[]
        while node!=None:
            a.append(node.val)
            node=node.next
        a.sort()
        node=head
        i=0
        while node!=None:
            node.val=a[i]
            node=node.next
            i+=1
        return head
        