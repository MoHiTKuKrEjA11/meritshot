#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            res = max(res, arr[i] ^ arr[j]);
        }
    }
    return res;
}

int main() {
    // Sample input
    int n = 6;
    vector<int> arr = {3, 10, 5, 25, 2, 8};

    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    cout << "Maximum XOR of two numbers: " << solve(arr) << endl;
}
