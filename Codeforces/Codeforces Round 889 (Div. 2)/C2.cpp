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

int n, mxidx, mnidx;

vector<pi> sol1(vector<ll> v) {
    vector<pi> ans;
    while (abs(v[mxidx]) < abs(v[mnidx])) {
        v[mxidx] += v[mxidx];
        ans.push_back({mxidx, mxidx});
    }
    for (int i=0; i<n; i++) {
        if (v[i] < 0) ans.push_back({i, mxidx});
    }
    for (int i=1; i<n; i++) {
        ans.push_back({i, i-1});
    }
    return ans;
}

vector<pi> sol2(vector<ll> v) {
    int n = v.size();
    vector<pi> ans;
    while (abs(v[mnidx]) < abs(v[mxidx])) {
        v[mnidx] += v[mnidx];
        ans.push_back({mnidx, mnidx});
    }
    for (int i=0; i<n; i++) {
        if (v[i] > 0) ans.push_back({i, mnidx});
    }
    for (int i=n-1; i>=1; i--) {
        ans.push_back({i-1, i});
    }
    return ans;
}

void solve(int CASE) {
    cin >> n;
    vector<ll> v(n);
    vector<pi> ans;
    int mcnt = 0;
    int pcnt = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] > 0) pcnt++;
        else if (v[i] < 0) mcnt++;
    }
    if (pcnt == 0 && mcnt == 0) {
        cout << 0 << '\n';
        return;
    }
    if (pcnt == 0) {
        for (int i=n-1; i>=1; i--) {
            ans.push_back({i-1, i});
        }
    }
    else if (mcnt == 0) {
        for (int i=1; i<n; i++) {
            ans.push_back({i, i-1});
        }
    }
    else {
        mxidx = max_element(v.begin(), v.end()) - v.begin();
        mnidx = min_element(v.begin(), v.end()) - v.begin();
        vector<pi> ans1 = sol1(v);
        vector<pi> ans2 = sol2(v);
        if (ans1.size() < ans2.size()) ans = ans1;
        else ans = ans2;
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
    cout << '\n';
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