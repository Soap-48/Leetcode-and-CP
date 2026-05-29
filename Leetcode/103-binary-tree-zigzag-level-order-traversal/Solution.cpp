/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> a;
        if(root==NULL)
            return a;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            queue<TreeNode*> b;
            vector<int> v;
            while(!q.empty()){
                if(q.front()->left!=NULL)   b.push(q.front()->left);
                if(q.front()->right!=NULL)   b.push(q.front()->right);
                v.push_back(q.front()->val);
                q.pop();
            }
            if(flag)
                reverse(v.begin(),v.end());
            flag=!flag;
            a.push_back(v);
            q=b;
        }
        return a;
    }
};