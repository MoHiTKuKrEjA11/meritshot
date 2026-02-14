#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void build(vector<int>& nums, int idx, int l, int r) {
    if(l == r) {
        seg[idx] = nums[l];
        return;
    }

    int mid = (l + r) / 2;

    build(nums, 2*idx + 1, l, mid);
    build(nums, 2*idx + 2, mid + 1, r);

    seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
}

int query(int idx, int l, int r, int ql, int qr) {

    if(ql <= l && r <= qr) {
        return seg[idx];
    }

    if(r < ql || l > qr) {
        return INT_MAX;
    }

    int mid = (l + r) / 2;

    int leftMin = query(2*idx + 1, l, mid, ql, qr);
    int rightMin = query(2*idx + 2, mid + 1, r, ql, qr);

    return min(leftMin, rightMin);
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    seg.resize(4 * n);

    build(nums, 0, 0, n - 1);

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}
