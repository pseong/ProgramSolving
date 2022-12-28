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

vector<int> v;
int n, m;

bool f(int x) {
    int cnt = 0;
    for (int i=0; i<m; i++) {
        cnt += (v[i] + x - 1) / x;
    }
    return cnt <= n;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    v.resize(m);
    for (int i=0; i<m; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int lo = 1;
    int hi = 1e9;
    int ans = 0;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (f(m)) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << '\n';
}