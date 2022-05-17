#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<vector<ll>> v(n+1, vector<ll>(2, 0));
	ll sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0];
		sum += v[i][0];
    }
    
	ll last = 0;
	ll val = 0;
    for (int z=1; z<=q; z++) {
        int what, i, x;
        cin >> what;
        if (what == 1) {
            cin >> i >> x;
			if (v[i][1] != last) {
				v[i][1] = last;
				v[i][0] = val;
			}
			ll diff = x - v[i][0];
			v[i][0] = x;
			sum += diff;
			cout << sum << '\n';
        }
        else {
            cin >> x;
			last = z;
			val = x;
			sum = val * n;
			cout << sum << '\n';
        }
    }
}