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
    int n;
    cin >> n;
    vector<ll> v(n + 1), right(n + 1), left(n + 1);
    ll sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll m = 0;
    deque<pll> q;
    for (int i=1; i<=n; i++) {
        while (q.size() && q.back().second - m >= v[i]) {
            right[q.back().first] = i;
            q.pop_back();
        }
        while (q.size() && q.front().second - m == 0) {
            right[q.front().first] = -1;
            q.pop_front();
        }
        q.push_back({i, v[i] + m});
        m += 1;
    }
    while (q.size()) {
        right[q.back().first] = n + 1;
        q.pop_back();
    }

    m = 0;
    for (int i=n; i>=1; i--) {
        while (q.size() && q.back().second - m >= v[i]) {
            left[q.back().first] = i;
            q.pop_back();
        }
        while (q.size() && q.front().second - m == 0) {
            left[q.front().first] = -1;
            q.pop_front();
        }
        q.push_back({i, v[i] + m});
        m += 1;
    }
    while (q.size()) {
        left[q.back().first] = 0;
        q.pop_back();
    }
    
    vector<ll> cleft(n + 1), cright(n + 1);
    for (int i=n; i>=1; i--) {
        if (right[i] == -1) {
            cright[i] = (v[i] + 1) * v[i] / 2;
        }
        else if (right[i] == n + 1) {
            ll d = n - i + 1;
            cright[i] = d * (2*v[i] - (d-1)) / 2;
        }
        else {
            ll d = right[i] - i;
            cright[i] = d * (2*v[i] - (d-1)) / 2 + cright[right[i]];
        }
    }
    for (int i=1; i<=n; i++) {
        if (left[i] == -1) {
            cleft[i] = (v[i] + 1) * v[i] / 2;
        }
        else if (left[i] == 0) {
            ll d = i;
            cleft[i] = d * (2*v[i] - (d-1)) / 2;
        }
        else {
            ll d = i - (left[i] + 1) + 1;
            cleft[i] = d * (2*v[i] - (d-1)) / 2 + cleft[left[i]];
        }
    }
    ll ans = 1e18;
    for (int i=1; i<=n; i++) {
        ll d = sum - (cleft[i] + cright[i] - v[i]);
        ans = min(ans, d + v[i]);
    }
    cout << ans << '\n';
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