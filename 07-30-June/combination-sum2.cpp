#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;

    void solve(vector<int>& arr, int target, int idx, vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == n || target < 0)
            return;

        // TAKE
        temp.push_back(arr[idx]);
        solve(arr, target - arr[idx], idx + 1, temp, ans);
        temp.pop_back();

        // NOT TAKE → skip duplicates
        while (idx + 1 < n && arr[idx] == arr[idx + 1])
            idx++;

        solve(arr, target, idx + 1, temp, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        n = arr.size();
        vector<vector<int>> ans;
        vector<int> temp;

        solve(arr, target, 0, temp, ans);

        return ans;
    }
};
