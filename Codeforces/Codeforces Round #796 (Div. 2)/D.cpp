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
        int n, k; cin >> n >> k;
        vector<ll> v(n);
        ll sum = 0;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if (n == 1) {
            cout << sum + k - 1 << '\n';
            continue;
        }
        if (k < n) {
            ll mx = 0;
            ll res = 0;
            int i=0;
            for (;i<k; i++) res += v[i];
            mx = max(mx, res);
            for (int i=k; i<n; i++) {
                res += v[i];
                res -= v[i-k];
                mx = max(mx, res);
            }
            cout << mx + (k-1)*k/2 << '\n';
        }
        else {
            sum += (n-1)*n/2;
            k -= (n-1);
            k--;
            sum += k * n;
            cout << sum << '\n';
        }
    }
}