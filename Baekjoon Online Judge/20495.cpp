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

    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        l[i] = a - b;
        r[i] = a + b;
    }
    auto L = l, R = r;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for (int i=0; i<n; i++) {
        int lo = lower_bound(r.begin(), r.end(), L[i]) - r.begin() + 1;
        int hi = upper_bound(l.begin(), l.end(), R[i]) - l.begin();
        cout << lo << ' ' << hi << '\n';
    }
}