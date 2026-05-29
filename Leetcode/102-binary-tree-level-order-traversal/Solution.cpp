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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
       if(root==NULL) {
            return v;
       }
        vector<int> a;
        int length=1;
        int nlength=0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *c=NULL;
        while(!q.empty()){
            while(length){
                c=q.front();
                q.pop();
                length-=1;
                if(c->left!=NULL) {q.push(c->left);nlength+=1;}
                if(c->right!=NULL) {q.push(c->right);nlength+=1;}
                a.push_back(c->val);
            }
            v.push_back(a);
            a.clear();
            length=nlength;
            nlength=0;
        }
    return v;
    }
};