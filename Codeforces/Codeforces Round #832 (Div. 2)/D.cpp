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
    vector<int> v(n + 1), pref(n + 1), zero(n + 1), same(n + 1);
    map<int, int> even, odd;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        pref[i] = pref[i-1] ^ v[i];
        if (v[i] == 0) zero[i] = zero[i-1];
        else zero[i] = i;
        if (i%2) {
            if (even.count(pref[i])) same[i] = even[pref[i]];
            odd[pref[i]] = i;
        }
        else {
            if (odd.count(pref[i])) same[i] = odd[pref[i]];
            even[pref[i]] = i;
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if ((pref[r] ^ pref[l-1]) != 0) {
            cout << -1 << '\n';
        }
        else if (zero[r] < l) {
            cout << 0 << '\n';
        }
        else if ((r-l+1) % 2) {
            cout << 1 << '\n';
        }
        else if (v[l] == 0 || v[r] == 0) {
            cout << 1 << '\n';
        }
        else if (same[r] >= l) {
            cout << 2 << '\n';
        }
        else cout << -1 << '\n';
    }
}