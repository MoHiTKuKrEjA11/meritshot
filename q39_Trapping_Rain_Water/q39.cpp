#include <bits/stdc++.h>
using namespace std;

vector<int> gr(vector<int>& height) {
    int n = height.size();
    vector<int> gright(n);

    int mx = INT_MIN;

    for(int i = n - 1; i >= 0; i--) {
        mx = max(mx, height[i]);
        gright[i] = mx;
    }

    return gright;
}

vector<int> gl(vector<int>& height) {
    int n = height.size();
    vector<int> gleft(n);

    int mx = INT_MIN;

    for(int i = 0; i < n; i++) {
        mx = max(mx, height[i]);
        gleft[i] = mx;
    }

    return gleft;
}

int solve(vector<int>& height) {
    vector<int> gright = gr(height);
    vector<int> gleft = gl(height);

    int n = height.size();
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += min(gright[i], gleft[i]) - height[i];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << solve(height) << endl;

    return 0;
}
