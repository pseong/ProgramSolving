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




struct Seg {
    vector<int> an;
    vector<vector<int>> seg;

    void ii(int n) {
        an.resize(2*n+1000);
        seg.resize(8*n+1000);
    }

    void init(int node, int s, int e) {
        if (s==e) {
            seg[node].push_back(an[s]);
            return;
        }
        int mid = (s + e) / 2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        seg[node] = seg[node*2];
        seg[node].insert(seg[node].end(), seg[node*2+1].begin(), seg[node*2+1].end());
        sort(seg[node].begin(), seg[node].end());
    }

    int query(int node, int s, int e, int l, int r, int k) {
        if (e<l || r<s) return 0;
        if (l<=s && e<=r) {
            return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);
        }
        int mid = (s + e) / 2;
        return query(node*2, s, mid, l, r, k) + query(node*2+1, mid+1, e, l, r, k);
    }
};



void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    vector<pi> vv;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        if (v[i] < i) vv.push_back({i, v[i]});
    }
    int z = vv.size();
    Seg seg;
    seg.ii(z);
    for (int i=1; i<=z; i++) {
        seg.an[i] = vv[i-1].second;
    }
    if (z == 0) {
        cout << 0 << '\n';
        return;
    }

    seg.init(1, 1, z);
    
    multiset<int> st;
    ll ans = 0;
    for (int i=0; i<z; i++) {
        int idx = i+1;
        ans += seg.query(1, 1, z, idx+1, z, vv[i].first);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}