#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>& heights) {
    int n = heights.size();
    vector<int> next(n);
    stack<int> st;
    st.push(-1);

    for(int i = n - 1; i >= 0; i--) {
        while(st.top() != -1 && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        next[i] = st.top();
        st.push(i);
    }

    return next;
}

vector<int> prevSmaller(vector<int>& heights) {
    int n = heights.size();
    vector<int> prev(n);
    stack<int> st;
    st.push(-1);

    for(int i = 0; i < n; i++) {
        while(st.top() != -1 && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        prev[i] = st.top();
        st.push(i);
    }

    return prev;
}

int solve(vector<int>& heights) {
    int n = heights.size();

    vector<int> next = nextSmaller(heights);
    vector<int> prev = prevSmaller(heights);

    int ans = 0;

    for(int i = 0; i < n; i++) {

        if(next[i] == -1) {
            next[i] = n;
        }

        int h = heights[i];
        int w = next[i] - prev[i] - 1;

        int area = h * w;
        ans = max(ans, area);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int res = solve(heights);
    cout << res << endl;

    return 0;
}
