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

int l, r, u, d, n;
const int inf = 1000000000;
bool _chk(int m, vector<pi>& v) {
    int ll, rr, uu, dd;
    for (int i=0; i<(int)v.size(); i++) {
        if (i == 0) {
            ll = v[i].first, rr = v[i].first;
            uu = v[i].second, dd = v[i].second;
        }
        else {
            ll = min(ll, v[i].first);
            rr = max(rr, v[i].first);
            uu = max(uu, v[i].second);
            dd = min(dd, v[i].second);
        }
    }
    bool ok = 1;
    for (int i=0; i<(int)v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        if (!(x <= ll + m && y <= dd + m || x >= rr - m && y >= uu - m)) ok = 0;
    }
    if (ok) return 1;
    ok = 1;
    for (int i=0; i<(int)v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        if (!(x <= ll + m && y >= uu - m || x >= rr - m && y <= dd + m)) ok = 0;
    }
    return ok;
}

bool chk(int m, vector<pi>& v) {
    vector<pi> tmp;
    for (int i=0; i<n; i++) {
        if (!(v[i].first <= l + m && v[i].second <= d + m)) tmp.push_back(v[i]);
    }
    if (_chk(m, tmp)) return 1;
    tmp.clear();
    for (int i=0; i<n; i++) {
        if (!(v[i].first <= l + m && v[i].second >= u - m)) tmp.push_back(v[i]);
    }
    if (_chk(m, tmp)) return 1;
    tmp.clear();
    for (int i=0; i<n; i++) {
        if (!(v[i].first >= r - m && v[i].second <= d + m)) tmp.push_back(v[i]);
    }
    if (_chk(m, tmp)) return 1;
    tmp.clear();
    for (int i=0; i<n; i++) {
        if (!(v[i].first >= r - m && v[i].second >= u - m)) tmp.push_back(v[i]);
    }
    if (_chk(m, tmp)) return 1;
    return 0;
}

void solve(int CASE) {
    cin >> n;
    vector<pi> v(n);
    set<pi> st;
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        if (i == 0) {
            l = v[i].first, r = v[i].first;
            u = v[i].second, d = v[i].second;
        }
        else {
            l = min(l, v[i].first);
            r = max(r, v[i].first);
            u = max(u, v[i].second);
            d = min(d, v[i].second);
        }
        st.insert(v[i]);
    }
    if (st.size() < 4) {
        cout << 0 << '\n';
        return;
    }
    chk(1, v);
    int lo = 1;
    int hi = max(r - l, u - d);
    int ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (chk(mid, v)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}