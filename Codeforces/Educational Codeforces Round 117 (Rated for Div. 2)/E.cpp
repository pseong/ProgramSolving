#include <bits/stdc++.h>
#define int long long
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

int expect[202020];
void solve() {
    int n; cin >> n;
    vector<int> m(n+1), k(n+1);
    for (int i=1; i<=n; i++) {
        cin >> m[i] >> k[i];
    }

    vector<int> ans;
    int anse = 0;
    for (int t=1; t<=20; t++) {
        memset(expect, 0, sizeof expect);
        for (int i=1; i<=n; i++) {
            expect[m[i]] += min(k[i], t);
        }
        vector<pi> v;
        for (int i=1; i<=200000; i++) {
            if (expect[i] > 0) {
                v.push_back({expect[i], i});
            }
        }
        srtrev(v);
        int e = 0;
        vector<int> tmp;
        for (int i=0; i<min(t, (int)v.size()); i++) {
            e += v[i].first;
            tmp.push_back(v[i].second);
        }

        if (ans.size() == 0 || anse * t <= e * ans.size()) {
            anse = e;
            ans = tmp;
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}