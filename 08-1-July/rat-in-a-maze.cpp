#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(int i, int j, string t, vector<string>& ans, vector<vector<int>>& maze){
        int n = maze.size();
        if(i == n-1 && j == n-1){
            ans.push_back(t);
            return ;
        }
        if(!valid(i, j, n)) return ;
        if(maze[i][j] == 0) return ;
        
        maze[i][j] = 0;
        
        solve(i+1, j, t + 'D', ans, maze);
        solve(i, j-1, t + 'L', ans, maze);
        solve(i, j+1, t + 'R', ans, maze);
        solve(i-1, j, t + 'U', ans, maze);
        
        maze[i][j] = 1;
    }
    bool valid(int i, int j, int n){
        return i<n && j<n && i>=0 && j>=0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string t = "";
        int n = maze.size();
        solve(0, 0, t, ans, maze);
        return ans;
    }
};