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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> a;
        if(root==NULL)
            return  a;
        s.push(root);
        while(!s.empty()){
            if(s.top()!=NULL){
                s.push(s.top()->left);
            }
            else{
                s.pop();
                if(!s.empty()){
                    TreeNode* i=s.top();
                s.pop();
                if(i!=NULL) {
                    a.push_back(i->val);
                    s.push(i->right);
                }
            }
            }
        }
        return a;
    }
};