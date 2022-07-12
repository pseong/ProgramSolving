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


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        if (mp.find(a) == mp.end() || mp.find(b) == mp.end()) {
            no();
            continue;
        }
        int x = mp[a].front();
        int y = mp[b].back();
        if (x < y) {
            yes();
        }
        else no();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}