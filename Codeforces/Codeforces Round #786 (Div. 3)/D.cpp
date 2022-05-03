#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i=0; i<n; i++){
            cin >> v[i];
        }
        for (int i=n-2; i>=0; i-=2) {
            if (v[i] > v[i+1]) swap(v[i], v[i+1]);
        }
        vector<int> v2 = v;
        sort(v2.begin(), v2.end());
        if (v == v2) cout << "YES\n";
        else cout << "NO\n";
    }
}