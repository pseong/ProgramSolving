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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n);
    int p1 = 0, p2 = 0, pn = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] == 1) p1 = i + 1;
        else if (v[i] == 2) p2 = i + 1;
        else if (v[i] == n) pn = i + 1;
    }
    vector<int> w{p1, p2, pn};
    sort(all(w));
    if (w[1] != pn) cout << w[1] << ' ' << pn << '\n';
    else cout << 1 << ' ' << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}