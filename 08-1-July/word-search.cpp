#include<bits/stdc++.h>
using namespace std;


class Solution {
    bool solve(int i, int j, string& w, vector<vector<char>>& b, int idx, int n, int m){
        if(idx == w.length()) return true;
        if(!valid(i, j, n, m)) return false;
        if(b[i][j] != w[idx] || b[i][j] == '*') return false;
        char t = b[i][j];
        b[i][j] = '*';
        bool a = solve(i, j+1, w, b, idx+1, n, m);
        bool bb = solve(i, j-1, w, b, idx+1, n, m);
        bool c = solve(i+1, j, w, b, idx+1, n, m);
        bool d = solve(i-1, j, w, b, idx+1, n, m);
        b[i][j] = t;
        if(a || bb || c || d) return true;
        return false;
        

    }
    bool valid(int i, int j, int n, int m){
        return i<n && j<m && i>=0 && j>=0;
    }
public:
    bool exist(vector<vector<char>>& b, string w) {
        int n = b.size();
        int m = b[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(b[i][j] == w[0]){
                    if(solve(i, j, w, b, 0, n, m)) return true;
                }
            }
        }
        return false;
    }
};