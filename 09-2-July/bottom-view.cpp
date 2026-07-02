/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    map<int, pair<int, int>> m;
    void dfs(Node* root, int l, int im){
        if(root == nullptr) return ;
        if(!m.count(im) || l >= m[im].first){
            m[im] = {l, root->data};
        }
        
        dfs(root->left, l+1, im-1);
        dfs(root->right, l+1, im+1);
    }
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        dfs(root, 0, 0); // height, im
        for(auto e: m){
            ans.push_back(e.second.second);
        }
        return ans;
    }
};













