# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans=0
        def c(node,h):
            nonlocal ans
            if node is not None:
                l=c(node.left,h)
                r=c(node.right,h)
                ans=max(ans,l+r)
                return max(l,r)+1
            return h
        c(root,0)
        return ans