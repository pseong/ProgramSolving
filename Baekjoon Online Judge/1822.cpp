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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int i=0; i<n; i++) {
        cin >> v1[i];
    }
    for (int i=0; i<m; i++) {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> ans;
    for (int i=0; i<n; i++) {
        auto it = lower_bound(v2.begin(), v2.end(), v1[i]);
        if (it == v2.end() || *it != v1[i]) ans.push_back(v1[i]);
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}