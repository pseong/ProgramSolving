#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

ll g(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'a' + 10;
}

ll f(string s, int d) {
    for (int i=0; i<(int)s.size(); i++) {
        if (g(s[i]) >= d) return -1;
    }
    ll res = 0;
    ll x = 1;
    for (int i=(int)s.size()-1; i>=0; i--) {
        res += g(s[i]) * x;
        x *= d;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector<tll> ans;
    for (int i=2; i<=36; i++) {
        for (int j=2; j<=36; j++) {
            if (i == j) continue;
            ll A = f(a, i);
            ll B = f(b, j);
            if (A == -1 || B == -1) continue;
            if (A == B) ans.push_back({A, i, j});
        }
    }
    if (ans.size() == 0) cout << "Impossible\n";
    else if (ans.size() >= 2) cout << "Multiple\n";
    else {
        auto [a, b, c] = ans[0];
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}