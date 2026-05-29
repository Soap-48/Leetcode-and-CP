# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        nodes={}
        l,r=1e6,0
        if root is None:
            return [[]]
        def che(node,c,ro):
            nonlocal nodes,l,r
            if node is not None:
                if c not in nodes:
                    nodes[c]=[]
                nodes[c].append((ro,node.val))
                che(node.left,c-1,ro+1)
                che(node.right,c+1,ro+1)
                l=min(l,c)
                r=max(r,c)
        che(root,0,0)
        ans=[]
        for i in range(l,r+1):
            a=sorted(nodes[i])            
            b=[y[1] for y in a]
            ans.append(b)
        return ans

