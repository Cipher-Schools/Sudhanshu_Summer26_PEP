#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& temp, int n) {
        if (n < 0) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (target >= arr[n]) {
            temp.push_back(arr[n]);
            solve(arr, target - arr[n], ans, temp, n);
            temp.pop_back();
        }
        solve(arr, target, ans, temp, n - 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, ans, temp, candidates.size() - 1);
        return ans;
    }
};