#include <bits/stdc++.h>
using namespace std;

int solve(int target, int startFuel, vector<vector<int>>& st) {

    priority_queue<int> pq;

    int fuel = startFuel;
    int stops = 0;
    int i = 0;
    int n = st.size();

    while(fuel < target) {

        while(i < n && st[i][0] <= fuel) {
            pq.push(st[i][1]);
            i++;
        }

        if(pq.empty()) {
            return -1;
        }

        fuel += pq.top();
        pq.pop();
        stops++;
    }

    return stops;
}

int main() {

    int target, startFuel;
    cin >> target >> startFuel;

    int n;
    cin >> n;

    vector<vector<int>> st(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> st[i][0] >> st[i][1];
    }

    cout << solve(target, startFuel, st) << endl;

    return 0;
}
