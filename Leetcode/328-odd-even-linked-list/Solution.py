# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        else:
            h1,h2=head,head.next
            temp=head.next
            p1,p2=h1,h2
            while h1!=None and h2!=None:
                h1.next=h1.next.next
                if h2.next!=None:
                    h2.next=h2.next.next
                p1,p2=h1,h2
                h1=h1.next
                h2=h2.next
            if h1!=None:
                h1.next=temp
            else:
                p1.next=temp
            return head