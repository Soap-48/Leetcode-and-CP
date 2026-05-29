# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        flag=True
        def check(n1,n2):
            nonlocal flag
            if not flag:
                return
            if n1 is not None and n2 is not None:
                if n1.val!=n2.val:
                    flag=False
                    return
                else:
                    check(n1.left,n2.left)
                    check(n1.right,n2.right)
            else:
                if n1 is None and n2 is None:
                    return
                else:
                    flag=False
        check(p,q)
        return flag