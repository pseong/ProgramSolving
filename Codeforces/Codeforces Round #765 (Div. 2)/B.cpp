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

vector<int> a[160000];

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<160000; i++) {
        a[i].clear();
    }
    for (int i=0; i<n; i++) {
        cin >> v[i];
        a[v[i]].push_back(i);
    }
    int ans = -1;
    for (int i=0; i<160000; i++) {
        if (a[i].size() >= 2) {
            for (int j=1; j<a[i].size(); j++) {
                ans = max(ans, n-(a[i][j] - a[i][j-1]));
            }
        }
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