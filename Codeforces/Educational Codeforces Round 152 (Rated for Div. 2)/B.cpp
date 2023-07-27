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

bool cmp(pi a, pi b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    for (int i=0; i<n; i++) {
        v[i] %= k;
        if (v[i] == 0) v[i] += k;
    }
    vector<pi> w(n);
    for (int i=0; i<n; i++) {
        w[i] = { v[i], i };
    }
    sort(w.begin(), w.end(), cmp);
    for (int i=0; i<n; i++) {
        cout << w[i].second + 1 << ' ';
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