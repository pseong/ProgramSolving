#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    int ans = 0;
    ans = (v2[0]+1)/2 + (v2[1]+1)/2;
    for (int i=0; i<n-1; i++) {
        ans = min(ans, max({(v[i]+1)/2, (v[i+1]+1)/2, (v[i]+v[i+1]+2)/3}));
    }
    for (int i=0; i<n-2; i++) {
        ans = min({ans, (v[i]+v[i+2]+1)/2});
    }
    cout << ans;
}