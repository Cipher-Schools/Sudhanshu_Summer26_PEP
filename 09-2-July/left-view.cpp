/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        dfs(0, ans, root);
        return ans;
    }
    void dfs(int h, vector<int>&ans, Node* root){
        if(!root) return;
        if(ans.size() == h) ans.push_back(root->data);
        dfs(h+1, ans, root->left);
        dfs(h+1, ans, root->right);
    } 
};





