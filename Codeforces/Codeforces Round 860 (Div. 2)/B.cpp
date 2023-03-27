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
    int m;
    cin >> m;
    map<int, int> mp;
    for (int i=1; i<=m; i++) {
        int n;
        cin >> n;
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            mp[a] = i;
        }
    }
    map<int, int> ans;
    for (auto [x, y] : mp) {
        ans[y] = x;
    }
    vector<int> a(m + 1);
    for (int i=1; i<=m; i++) {
        if (ans[i] == 0) {
            cout << -1 << '\n';
            return;
        }
        a[i] = ans[i];
    }
    for (int i=1; i<=m; i++) cout << a[i] << ' ';
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