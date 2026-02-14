#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& pre, int l, int r, int k, vector<vector<int>>& dp) {

    if(l == r) {
        return 0;
    }

    if(dp[l][r] != -1) {
        return dp[l][r];
    }

    int mn = INT_MAX;

    for(int m = 0; l + m < r; m += k - 1) {

        int left = dfs(pre, l, l + m, k, dp);
        int right = dfs(pre, l + m + 1, r, k, dp);

        mn = min(mn, left + right);
    }

    int cost = 0;

    if((r - l) % (k - 1) == 0) {
        cost = pre[r + 1] - pre[l];
    }

    return dp[l][r] = mn + cost;
}

int solve(vector<int>& stones, int k) {

    int n = stones.size();

    if((n - 1) % (k - 1) != 0) {
        return -1;
    }

    vector<int> pre(1, 0);
    partial_sum(stones.begin(), stones.end(), back_inserter(pre));

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return dfs(pre, 0, n - 1, k, dp);
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> stones(n);
    for(int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << solve(stones, k) << endl;

    return 0;
}
