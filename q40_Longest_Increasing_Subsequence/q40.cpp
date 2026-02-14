#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();

    vector<int> vec(n, 0);
    vec[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {

        int maxi = 0;

        for(int j = i + 1; j < n; j++) {
            if(nums[j] > nums[i]) {
                maxi = max(maxi, vec[j]);
            }
        }

        vec[i] = maxi + 1;
    }

    int ans = INT_MIN;

    for(int i = 0; i < n; i++) {
        ans = max(ans, vec[i]);
    }

    return ans;
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
