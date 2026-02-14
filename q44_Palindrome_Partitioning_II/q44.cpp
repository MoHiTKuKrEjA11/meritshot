#include <bits/stdc++.h>
using namespace std;

bool isPal(int l, int r, string& s) {
    while(l < r) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int dfs(int l, int r, int cur, int& val, string& s, vector<vector<int>>& dp) {

    if(dp[l][r] != INT_MAX) {
        return dp[l][r];
    }

    if(l == r || isPal(l, r, s)) {
        dp[l][r] = 0;
        return 0;
    }

    if(cur >= val) {
        return s.size() - 1;
    }

    int ans = INT_MAX;

    for(int i = l; i < r; i++) {

        int left = dfs(l, i, cur + 1, val, s, dp);
        int right = dfs(i + 1, r, cur + 1 + left, val, s, dp);

        ans = min(ans, left + right + 1);
    }

    val = min(val, ans);
    dp[l][r] = ans;

    return ans;
}

int solve(string& s) {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    int val = n - 1;

    return dfs(0, n - 1, 0, val, s, dp);
}

int main() {
    string s;
    cin >> s;

    cout << solve(s) << endl;

    return 0;
}
