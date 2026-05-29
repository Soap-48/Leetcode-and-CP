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
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head==None or head.next==None or k==1:
            return head
        else:
            prev=None
            l,r=head,head
            count=0
            while r!=None:
                count+=1
                if count ==k:
                    nxt=r.next
                    r.next=None
                    a=self.reverse(l)
                    if prev==None:
                        head=a
                    else:
                        prev.next=a
                    prev=l
                    r=nxt
                    l=nxt
                    count=0
                else:
                    r=r.next
                if prev !=None:
                    prev.next=l
            return head
                
                
            
