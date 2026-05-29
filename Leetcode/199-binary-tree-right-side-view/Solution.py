# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # ans=[]
        # h=0
        # h2=1
        # if root is None:
        #     return ans
        # def che(node):
        #     nonlocal ans,h
        #     h+=1
        #     ans.append(node.val)
        #     if node.right is not None:
        #         che(node.right)
        #     elif node.left is not None:
        #         che(node.left)
        # che(root)
        # def che2(node):
        #     nonlocal ans,h,h2
        #     h2+=1
        #     if h2>h:
        #         ans.append(node.val)
        #     if node.right is not None:
        #         che2(node.right)
        #     elif node.left is not None:
        #         che2(node.left)
        # if root.left is not None:
        #     che2(root.left)
        # return ans
        nodes={}
        r=0
        if root is None:
            return []
        def che(node,c,ro,j):
            nonlocal nodes,r
            if node is not None:
                if ro not in nodes:
                    nodes[ro]=(c,node.val)
                if c>=nodes[ro][0]:
                    nodes[ro]=(c,node.val)
                che(node.left,c-j,ro+1,j/2)
                che(node.right,c+j,ro+1,j/2)
                r=max(r,ro)
        che(root,0,0,1000.0)
        ans=[]
        for i in range(0,r+1):
            ans.append(nodes[i][1])
        return ans