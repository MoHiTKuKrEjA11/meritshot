#include <bits/stdc++.h>
using namespace std;

bool inside(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(vector<vector<int>>& mat, vector<vector<int>>& dp, int i, int j, int n, int m) {

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int a = 0, b = 0, c = 0, d = 0;

    if(inside(i + 1, j, n, m) && mat[i + 1][j] > mat[i][j]) {
        a = dfs(mat, dp, i + 1, j, n, m);
    }

    if(inside(i - 1, j, n, m) && mat[i - 1][j] > mat[i][j]) {
        b = dfs(mat, dp, i - 1, j, n, m);
    }

    if(inside(i, j + 1, n, m) && mat[i][j + 1] > mat[i][j]) {
        c = dfs(mat, dp, i, j + 1, n, m);
    }

    if(inside(i, j - 1, n, m) && mat[i][j - 1] > mat[i][j]) {
        d = dfs(mat, dp, i, j - 1, n, m);
    }

    dp[i][j] = 1 + max(a, max(b, max(c, d)));

    return dp[i][j];
}

int solve(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(dp[i][j] == -1) {
                ans = max(ans, dfs(mat, dp, i, j, n, m));
            }
        }
    }

    return ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << solve(mat) << endl;

    return 0;
}
