# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        flag=True
        def ch(node,h):
            nonlocal flag
            if node!=None:
                h1=ch(node.left,h+1)
                h2=ch(node.right,h+1)
                #print(node.val,h1,h2)
                if abs(h1-h2)>1:
                    flag=False
                return max(h1,h2)
            else:
                return h
        ch(root,0)
        return flag