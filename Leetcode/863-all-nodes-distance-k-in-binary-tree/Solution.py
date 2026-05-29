# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        p={}
        vis={}
        p[root]=None
        def pbuilder(node):
            nonlocal p,vis
            vis[node]=1
            if node.left:
                p[node.left]=node
                pbuilder(node.left)
            if node.right:
                p[node.right]=node
                pbuilder(node.right)
        pbuilder(root)
        ans=[]
        def dfs(node,d):
            nonlocal ans
            if d==k:
                ans.append(node.val)
            vis[node]=0
            if node.left and vis[node.left]:
                dfs(node.left,d+1)
            if node.right and vis[node.right]:
                dfs(node.right,d+1)
            if p[node] and vis[p[node]]:
                dfs(p[node],d+1)
        dfs(target,0)
        return ans
