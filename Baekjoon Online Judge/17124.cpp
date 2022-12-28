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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll sum = 0;
    for (int i=0; i<n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        vector<int> v;
        if (it != b.begin()) v.push_back(*(prev(it)));
        if (it != b.end()) v.push_back(*it);
        if (v.size() == 1) sum += v[0];
        else {
            if (abs(v[0] - a[i]) == abs(v[1] - a[i])) sum += v[0];
            else if (abs(v[0] - a[i]) > abs(v[1] - a[i])) sum += v[1];
            else if (abs(v[0] - a[i]) < abs(v[1] - a[i])) sum += v[0];
        }
    }
    cout << sum << '\n';
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