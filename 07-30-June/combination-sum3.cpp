#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int n, int tar) {
        vector<int> t;
        vector<vector<int>> ans;
        solve(1, n, tar, t, ans);
        return ans;
    }
    private:
    void solve(int i, int n, int tar, vector<int>t, vector<vector<int>>& ans){
        if(n == 0){
            if(tar == 0) ans.push_back(t);
            return ;
        }
        if(tar < 0) return;
        for(int j=i;j<=9;++j){
            t.push_back(j);
            solve(j+1, n-1, tar-j, t, ans);
            t.pop_back();
        }
    }
};