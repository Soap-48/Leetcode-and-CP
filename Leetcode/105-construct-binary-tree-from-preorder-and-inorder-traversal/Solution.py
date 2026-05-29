# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        ma={}
        for i in range(0,len(inorder)):
            ma[inorder[i]]=i
        def help(pl,pr,il,ir):
            nonlocal  preorder,inorder
            if pl<=pr:
                node=TreeNode(preorder[pl])
                i=ma[preorder[pl]]
                node.left=help(pl+1,pl+i-il,il,i-1)
                node.right=help(pl+i-il+1,pr,i+1,ir)
                return node
            else:
                return None
        return help(0,len(preorder)-1,0,len(inorder)-1)