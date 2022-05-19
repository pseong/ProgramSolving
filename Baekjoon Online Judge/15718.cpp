#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll exgcd(ll a, ll b, ll &s, ll &t) { ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1; ll r, q; while (r2) { q = r1 / r2; r = r1 % r2; r1 = r2, r2 = r; s = s1 - q * s2; s1 = s2, s2 = s; t = t1 - q * t2; t1 = t2, t2 = t; } s = s1; t = t1; if (s <= 0) { s += b; t -= a; } return r1; }
ll inverse(ll A, ll B) { ll u, tmp; exgcd(A, B, u, tmp); return u; }

ll china(ll a, ll b, ll A, ll B) {
    ll s = 0, MOD = A * B;
	s = (s + B * inverse(B, A) % MOD * a % MOD) % MOD;
	s = (s + A * inverse(A, B) % MOD * b % MOD) % MOD;
	return s;
}

ll com97[100][100];
ll com1031[1100][1100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    com97[0][0] = 1;
    for (int i=1; i<100; i++) {
        com97[i][0] = 1;
        for (int j=1; j<=i; j++) {
            com97[i][j] = com97[i-1][j-1] + com97[i-1][j];
            com97[i][j] %= 97;
        }
    }

    com1031[0][0] = 1;
    for (int i=1; i<1100; i++) {
        com1031[i][0] = 1;
        for (int j=1; j<=i; j++) {
            com1031[i][j] = com1031[i-1][j-1] + com1031[i-1][j];
            com1031[i][j] %= 1031;
        }
    }
    
    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        if (k == 1) {
            if (n == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }
        else if (n == 0) {
            cout << 0 << '\n';
            continue;
        }
        ll ans97 = 1;
        ll _n = n-1;
        ll _k = k-2;
        while (_n || _k) {
            ans97 *= com97[_n%97][_k%97];
            ans97 %= 97;
            _n /= 97;
            _k /= 97;
        }

        ll ans1031 = 1;
        _n = n-1;
        _k = k-2;
        while (_n || _k) {
            ans1031 *= com1031[_n%1031][_k%1031];
            ans1031 %= 1031;
            _n /= 1031;
            _k /= 1031;
        }

        cout << china(ans97, ans1031, 97, 1031) << '\n';
    }
}