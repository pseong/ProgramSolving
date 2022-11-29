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
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

vector<ll> v;

void gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b) {
        v.push_back(a / b);
        a = a % b;
        swap(a, b);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    gcd(a, b);
    reverse(v.begin(), v.end());
    bool win = 1;
    for (ll i=1; i<(ll)v.size(); i++) {
        if (v[i] == 1) win ^= 1;
        else win = 1;
    }
    if (win) cout << "win\n";
    else cout << "lose\n";
}