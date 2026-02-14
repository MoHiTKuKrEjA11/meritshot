#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& height) {

    int n = height.size();
    int m = height[0].size();

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        vis[i][0] = 1;
        vis[i][m - 1] = 1;
        pq.push({height[i][0], {i, 0}});
        pq.push({height[i][m - 1], {i, m - 1}});
    }

    for(int j = 0; j < m; j++) {
        vis[0][j] = 1;
        vis[n - 1][j] = 1;
        pq.push({height[0][j], {0, j}});
        pq.push({height[n - 1][j], {n - 1, j}});
    }

    int ans = 0;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    while(!pq.empty()) {

        auto cur = pq.top();
        pq.pop();

        int h = cur.first;
        int r = cur.second.first;
        int c = cur.second.second;

        for(int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               !vis[nr][nc]) {

                ans += max(0, h - height[nr][nc]);

                pq.push({max(h, height[nr][nc]), {nr, nc}});
                vis[nr][nc] = 1;
            }
        }
    }

    return ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> height(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> height[i][j];
        }
    }

    cout << solve(height) << endl;

    return 0;
}
