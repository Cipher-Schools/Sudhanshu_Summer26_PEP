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
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            for(int i=0;i<n;++i){
                auto e = q.front();
                q.pop();
                t.push_back(e->val);
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }
            if(f){
                ans.push_back(t);
            }else{
                reverse(t.begin(), t.end());
                ans.push_back(t);
            }
            f = !f;
        }
        return ans;
    }
};


