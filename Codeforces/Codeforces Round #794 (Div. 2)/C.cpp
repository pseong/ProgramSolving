#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n), ans(n);
        for (int i=0; i<n; i++) cin >> v[i];
        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i+=2) {
            ans[i] = v[i/2];
        }
        for (int i=1; i<n; i+=2) {
            ans[i] = v[(v.size()+1)/2+(i/2)];
        }
        ans.insert(ans.begin(), ans.back());
        ans.push_back(ans[1]);
 
        bool ok = true;
        for (int i=1; i<(int) ans.size()-1; i+=2) {
            if (!(ans[i-1] > ans[i] && ans[i] < ans[i+1])) {
                ok = false;
            }
        }
        for (int i=2; i<(int) ans.size()-1; i+=2) {
            if (!(ans[i-1] < ans[i] && ans[i] > ans[i+1])) {
                ok = false;
            }
        }
        if (!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=1; i<(int) ans.size()-1; i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
}