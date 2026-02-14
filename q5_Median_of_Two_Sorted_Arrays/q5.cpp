#include <bits/stdc++.h>
using namespace std;

double solve(vector<int>& vec1, vector<int>& vec2) {
    vector<int> arr;
    double ans;
    int l1 = vec1.size(),l2 = vec2.size();
    int i=0,j=0;
    while(i<l1 && j<l2) {
        if(vec1[i]>vec2[j]) {
            arr.push_back(vec2[j]);
            j++;
        }
        else {
            arr.push_back(vec1[i]);
            i++;
        }
    }
    while(i<l1) {
        arr.push_back(vec1[i]);
        i++;
    }
    while(j<l2) {
        arr.push_back(vec2[j]);
        j++;
    }
    if((l1+l2)&1) {
        ans = arr[(l1+l2)/2];
    }
    else {
        int val = (l1+l2);
        ans = (arr[val/2] + arr[(val - 1)/2])/2.0;
    } 
    return ans;
}

int main()
{
	int m, n;
	cin >> m;
	vector<int> vec1(m);
	for(int i=0;i<m;i++) {
	    cin >> vec1[i];
	}
	
	cin >> n;
	vector<int> vec2(n);
	for(int i=0;i<n;i++) {
	    cin >> vec2[i];
	}

	double res = solve(vec1, vec2);
	cout << res << endl;

	return 0;
}