# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def slave(node):
            if node is None:
                return None
            if node.left is None and node.right is None:
                return node
            l1,l2=None,None
            if node.left:
                l1=slave(node.left)
                l1.right=node.right
            if node.right:
                l2=slave(node.right)
            if node.left:
                node.right=node.left
            node.left=None
            if l2 is None:
                l2=l1
            return l2
        slave(root)
