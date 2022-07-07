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
    vector<ll> v(n), pos, neg;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        if (v[i] > 0) {
            pos.push_back(v[i]);
        }
        else{
            neg.push_back(-v[i]);
        }
    }
    srt(pos);
    srt(neg);
    ll ans = 0;
    ll now = 0;
    for (int i=(int)pos.size()-1; i>=0; i-=k) {
        ans += pos[i]*2;
        now = max(now, pos[i]);
    }
    for (int i=(int)neg.size()- 1; i>=0; i-=k) {
        ans += neg[i]*2;
        now = max(now, neg[i]);
    }
    cout << ans - now << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}