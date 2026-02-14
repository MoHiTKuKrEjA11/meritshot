#include <bits/stdc++.h>
using namespace std;

bool dfs(string &s, string &p, int i, int j, vector<vector<int>> &dp) {

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(j == p.length()) {
        return dp[i][j] = (i == s.length());
    }

    bool match = (i < s.length()) && (p[j] == '.' || p[j] == s[i]);

    if(j + 1 < p.length() && p[j + 1] == '*') {

        bool skip = dfs(s, p, i, j + 2, dp);
        bool take = match && dfs(s, p, i + 1, j, dp);

        return dp[i][j] = (skip || take);
    }

    return dp[i][j] = (match && dfs(s, p, i + 1, j + 1, dp));
}

bool solve(string s, string p) {

    vector<vector<int>> dp(s.length() + 1,
                           vector<int>(p.length() + 1, -1));

    return dfs(s, p, 0, 0, dp);
}

int main() {

    string s, p;
    cin >> s >> p;

    if(solve(s, p)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
