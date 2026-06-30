#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string t = "";
        int o = n, c = n;
        solve(o, c, t, ans);
        return ans;
    }
    private:
    void solve(int o, int c, string t, vector<string>&ans){
        if(o == 0 && c == 0){
            ans.push_back(t);
            return ;
        }
        if(o > 0){
            solve(o-1, c, t + '(', ans);
        }
        if(c > o){
            solve(o, c-1, t + ')', ans);
        }
    }
};