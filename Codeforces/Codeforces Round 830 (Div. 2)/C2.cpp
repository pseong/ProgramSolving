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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1), p{ -1 };
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        if (v[i] != 0) p.push_back(i);
    }
    int m = p.size() - 1;
    vector<ll> sum(m + 1), xsum(m + 1);
    for (int i=1; i<=m; i++) {
        sum[i] = sum[i-1] + v[p[i]];
        xsum[i] = xsum[i-1] ^ v[p[i]];
    }
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(p.begin()+1, p.end(), L) - p.begin();
        int r = upper_bound(p.begin()+1, p.end(), R) - p.begin() - 1;
        ll cal = (sum[r] - sum[l-1]) - (xsum[r] ^ xsum[l-1]);
        int u = L, v = R;
        for (int i=l; i<=min(l+35, r); i++) {
            for (int j=max(r-35, i); j<=r; j++) {
                ll c = (sum[j] - sum[i-1]) - (xsum[j] ^ xsum[i-1]);
                if (cal == c) {
                    if (v - u > p[j] - p[i]) {
                        u = p[i];
                        v = p[j];
                    }
                }
            }
        }
        cout << u << ' ' << v << '\n';
    }
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