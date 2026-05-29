# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        p1,p2=headA,headB
        while p1!=None and p2!=None:
            p1=p1.next
            p2=p2.next
        if p1==None:
            p1=headB
        elif p2==None:
            p2=headA
        while p1!=None and p2!=None:
            p1=p1.next
            p2=p2.next
        if p1==None:
            p1=headB
        elif p2==None:
            p2=headA
        while p1!=None and p2!=None:
            if p1==p2:
                return p1
            p1=p1.next
            p2=p2.next
        else:
            return None