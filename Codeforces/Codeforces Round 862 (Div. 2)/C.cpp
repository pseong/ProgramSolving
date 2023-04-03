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
    ll n, m;
    cin >> n >> m;
    vector<double> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        double d = (double)b - sqrt(4*a*c);
        auto it = upper_bound(v.begin(), v.end(), (double)b-sqrt(4*a*c));
        if (it == v.end() || *it >= b + sqrt(4*a*c)) no();
        else {
            yes();
            cout << (ll)*it << '\n';
        }
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