#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {

    int n = nums.size();

    int total = 0;
    int curMax = 0, curMin = 0;
    int maxSum = nums[0], minSum = nums[0];

    for(int i = 0; i < n; i++) {

        curMax = max(curMax + nums[i], nums[i]);
        maxSum = max(maxSum, curMax);

        curMin = min(curMin + nums[i], nums[i]);
        minSum = min(minSum, curMin);

        total += nums[i];
    }

    if(minSum == total) {
        return maxSum;
    }

    return max(maxSum, total - minSum);
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
