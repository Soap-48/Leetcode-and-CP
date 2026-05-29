# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        a=[]
        def pot(node):
            if node!=None:
                pot(node.left)
                pot(node.right)
                a.append(node.val)
        pot(root)
        return a