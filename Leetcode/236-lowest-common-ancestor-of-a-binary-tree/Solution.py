# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        pa={}
        h={}
        def che(node,he):
            nonlocal pa,h
            he+=1
            if node.left is not None:
                pa[node.left]=node
                h[node.left]=he
                che(node.left,he)
            if node.right is not None:
                pa[node.right]=node
                h[node.right]=he
                che(node.right,he)    
        che(root,0)
        pa[root]=None
        h[root]=0
        while h[p]>h[q]:
            p=pa[p]
        while h[q]>h[p]:
            q=pa[q]
        while p is not None and q is not None and p is not q:
            p=pa[p]
            q=pa[q]
        return p