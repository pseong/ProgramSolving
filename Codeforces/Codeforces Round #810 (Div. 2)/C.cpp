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

vector<ll> v;
ll n, m, k;

bool poss(ll x, ll cnt) {
    vector<ll> v2;
    for (int i=0; i<k; i++) {
        if (v[i] >= x*2) v2.push_back(v[i]/x);
    }
    srt(v2);
    for (int i=0; i<(int)v2.size(); i++) {
        if (cnt - v2[i] != 1) cnt -= v2[i];
        else if (v2[i] >= 3) cnt -= v2[i]-1;
    }
    return cnt <= 0;
}

void solve(int CASE) {
    cin >> n >> m >> k;
    v.resize(k);
    for (int i=0; i<k; i++) {
        cin >> v[i];
    }
    if (poss(n, m) || poss(m, n)) yes();
    else no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}