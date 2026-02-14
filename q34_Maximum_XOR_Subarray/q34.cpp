#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    int res = 0;

    for(int i=0;i<n;i++){
        int x=0;
        for(int j=i;j<n;j++){
            x ^= arr[j];
            res = max(res, x);
        }
    }
    return res;
}

int main() {
    // Sample Input
    vector<int> arr = {8,1,2,12};

    cout << "Array: ";
    for(int x:arr) cout<<x<<" ";
    cout<<endl;

    cout << "Maximum XOR Subarray: " << solve(arr) << endl;
}
