#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void merge(vector<pair<int,int>>& vec, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<pair<int,int>> left(n1);
    vector<pair<int,int>> right(n2);

    for(int i = 0; i < n1; i++) {
        left[i] = vec[l + i];
    }

    for(int i = 0; i < n2; i++) {
        right[i] = vec[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if(left[i].first <= right[j].first) {
            vec[k++] = left[i++];
        }
        else {
            vec[k++] = right[j++];
        }
    }

    while(i < n1) {
        vec[k++] = left[i++];
    }

    while(j < n2) {
        vec[k++] = right[j++];
    }
}

void countPairs(vector<pair<int,int>>& vec, int l, int m, int r) {
    int j = m + 1;

    for(int i = l; i <= m; i++) {
        while(j <= r && vec[i].first > vec[j].first) {
            j++;
        }
        ans[vec[i].second] += (j - (m + 1));
    }
}

void mergeSort(vector<pair<int,int>>& vec, int l, int r) {
    if(l >= r) {
        return;
    }

    int m = l + (r - l) / 2;

    mergeSort(vec, l, m);
    mergeSort(vec, m + 1, r);

    countPairs(vec, l, m, r);
    merge(vec, l, m, r);
}

vector<int> solve(vector<int>& vec) {
    int n = vec.size();
    ans = vector<int>(n, 0);

    vector<pair<int,int>> arr;

    for(int i = 0; i < n; i++) {
        arr.push_back({vec[i], i});
    }

    mergeSort(arr, 0, n - 1);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<int> res = solve(vec);

    for(int i : res) {
        cout << i << " ";
    }

    return 0;
}
