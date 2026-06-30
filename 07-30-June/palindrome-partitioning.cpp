#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        int n = s.size();
        solve(0, n, t, ans, s);
        return ans;
    }
    private:
    void solve(int i, int n, vector<string> t, vector<vector<string>>& ans, string&s){
        if(i == n){
            ans.push_back(t);
            return ;
        }
        string x = "";
        for(int j=i;j<n;++j){
            x += s[j];
            if(isPalin(x)){
                t.push_back(x);
                solve(j+1, n, t, ans, s);
                t.pop_back();
            }
        }
    }
    bool isPalin(string s){
        int i=0, n = s.size();
        if(n == 1) return true;
        while(i<n/2){
            if(s[i] != s[n-i-1]) return false;
            i++;
        }
        return true;
    }
};