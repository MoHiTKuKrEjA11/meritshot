#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& nums, int k) {

    deque<int> dq;
    vector<int> ans;

    int n = nums.size();

    for(int i = 0; i < k; i++) {

        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    for(int i = k; i < n; i++) {

        ans.push_back(nums[dq.front()]);

        while(!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);

    return ans;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res = solve(nums, k);

    for(int x : res) {
        cout << x << " ";
    }

    return 0;
}
