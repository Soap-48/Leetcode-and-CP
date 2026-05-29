# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        p,q=l1.next,l2.next
        sum=l1.val+l2.val
        carry=sum//10
        head=ListNode(sum%10)
        l=head
        while p!=None or q!=None:
            sum=carry
            if p!=None:
                sum+=p.val
                p=p.next
            if q!=None:
                sum+=q.val
                q=q.next
            x=ListNode(sum%10)
            carry=sum//10
            l.next=x
            l=x
        if carry!=0:
            x=ListNode(carry)
            l.next=x
        return head