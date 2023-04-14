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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> chk(n + 1);
    vector<vector<int>> ans;
    if (x <= n) {
        chk[x] = 1;
        ans.push_back({x});
    }
    for (int i=1; i<=n; i++) {
        if ((i^x) <= n && chk[i] == 0 && chk[i^x] == 0) {
            chk[i] = 1;
            chk[(i^x)] = 1;
            ans.push_back({i, (i^x)});
        }
    }
    if (ans.empty()) {
        no();
        return;
    }
    int g = 0;
    vector<int> w;
    for (int i=1; i<=n; i++) {
        if (chk[i] == 0) {
            w.push_back(i);
            g ^= i;
        }
    }
    if (w.size()) {
        if (g == 0) {
            for (int e : w) {
                ans.back().push_back(e);
            }
        }
        else {
            no();
            return;
        }
    }
    if (ans.size() % 2 != k % 2) {
        no();
        return;
    }
    int diff = ans.size() - k;
    if (diff < 0) {
        no();
        return;
    }
    yes();
    vector<int> vv;
    for (int i=0; i<(int)diff + 1; i++) {
        for (int x : ans[i]) {
            vv.push_back(x);
        }
    }
    cout << vv.size() << ' ';
    for (int d : vv) {
        cout << d << ' ';
    }
    cout << '\n';
    for (int i=(int)diff + 1; i<(int)ans.size(); i++) {
        cout << ans[i].size() << ' ';
        for (int x : ans[i]) {
            cout << x << ' ';
        }
        cout << '\n';
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