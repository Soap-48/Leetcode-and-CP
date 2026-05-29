# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def he(node,h):
            if(node!=None):
                h1=he(node.left,h+1)
                h2=he(node.right,h+1)
                return max(h1,h2)
            else:
                return h
        return he(root,0)