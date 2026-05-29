"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        
        if head==None:
            return None
        nhead=Node(head.val,None,head)
        nnode=nhead
        node=head.next
        head.next=nhead
        while node!=None:
            x=Node(node.val,None,node)
            nxt=node.next
            nnode.next=x
            nnode=x
            node.next=x
            node=nxt
        nnode=nhead
        while nnode!=None:
            nnode.random=nnode.random.random
            if nnode.random!=None:
                nnode.random=nnode.random.next
            nnode=nnode.next
        return nhead