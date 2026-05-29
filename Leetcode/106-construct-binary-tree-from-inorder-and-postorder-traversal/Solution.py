# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        ma={}
        for i in range(0,len(inorder)):
            ma[inorder[i]]=i
        def help(pl,pr,il,ir):
            if pl<=pr:
                node=TreeNode(postorder[pr])
                i=ma[postorder[pr]]
                node.left=help(pl,pl+i-1-il,il,i-1)
                node.right=help(pl+i-il,pr-1,i+1,ir)
                return node
            else:
                return None
        return help(0,len(postorder)-1,0,len(inorder)-1)