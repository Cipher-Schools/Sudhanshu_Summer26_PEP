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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int ans = INT_MIN;
        int l = 0;
        int c = 0;
        int sum = 0;
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n == NULL){
                l++;
                if(ans < sum){
                    c = l;
                    ans = sum;
                }
                sum = 0;
                if(!q.empty()) q.push(NULL);
            }else{
                sum+=n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
        }
        return c;
    }
};