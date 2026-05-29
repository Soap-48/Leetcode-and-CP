# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans=-1000000000
        if root is None:
            return 0
        def help(node):
            nonlocal ans
            if node is not None:
                l=help(node.left)
                r=help(node.right)
                val=max([0,l,r,l+r])
                ans=max(ans,val+node.val)
                return max([0,l+node.val,r+node.val,node.val])
            else:
                return 0
        help(root)
        return ans