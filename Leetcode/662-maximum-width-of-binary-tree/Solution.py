# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q=[(root,1)]
        ans=0
        while q:
            temp=[]
            l,r=q[-1][1]*2+1,q[-1][1]
            for a,b in q:
                if a.left is not None:
                    temp.append((a.left,2*b))
                    l=min(l,2*b)
                    r=max(r,2*b)
                if a.right is not None:
                    temp.append((a.right,2*b+1))
                    r=max(r,2*b+1)
                    l=min(l,2*b+1)
            ans=max(ans,r-l+1)
            q=temp
        return max(ans,1)