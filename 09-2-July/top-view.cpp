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
    map<int, pair<int, int>> m;
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        dfs(0, 0, root);
        for(auto e: m){
            ans.push_back(e.second.second);
        }
        return ans;
    }
    void dfs(int h, int l, Node* root){
        if(!root) return ;
        if(!m.count(h) || l < m[h].first) m[h] = {l, root->data};
        dfs(h-1, l+1, root->left);
        dfs(h+1, l+1, root->right);
    }
};










