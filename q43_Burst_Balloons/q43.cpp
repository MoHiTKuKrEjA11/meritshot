#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n - 2; i >= 1; i--) {

        for(int j = 1; j <= n - 2; j++) {

            if(i > j) continue;

            int mx = INT_MIN;

            for(int k = i; k <= j; k++) {

                int val = nums[i - 1] * nums[k] * nums[j + 1]
                          + dp[i][k - 1]
                          + dp[k + 1][j];

                mx = max(mx, val);
            }

            dp[i][j] = mx;
        }
    }

    return dp[1][n - 2];
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << solve(nums) << endl;

    return 0;
}
