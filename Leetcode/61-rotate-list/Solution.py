# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self,head):
        a=None
        b=head
        while b!=None:
            c=b.next
            b.next=a
            a=b
            b=c
        return a

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k==0:
            return head
        n,nn=0,head
        while nn!=None:
            n+=1
            nn=nn.next
        k=k%n
        if k==0:
            return head
        count=0
        r=head
        while   count<=k:
            count+=1
            r=r.next
            if r==None:
                r=head
        l=head
        while r!=None:
            r=r.next
            l=l.next
        if l==None:
            l=head
        nxt=l.next
        if nxt==None:
            return head
        else:
            l.next=None
            a=self.reverse(head)
            b=self.reverse(nxt)
            head.next=b
            return self.reverse(a)