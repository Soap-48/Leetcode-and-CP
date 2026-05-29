# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        flag=True
        def che(a,b):
            nonlocal flag
            if flag:
                if a is not None and b is not None:
                    if a.val != b.val:
                        flag=False
                        return
                    else:
                        che(a.left,b.right)
                        che(a.right,b.left)
                elif a is not None or b is not None:
                    flag=False
        che(root.left,root.right)
        return flag