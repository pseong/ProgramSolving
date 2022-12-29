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

int n, k, v[101010];

bool cal(int m) {
    int cnt = 0;
    int now = 0;
    for (int i=0; i<n; i++) {
        now += v[i];
        if (now >= m) {
            cnt++;
            now = 0;
        }
    }
    return cnt >= k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int lo = 1;
    int hi = 2e6;
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cal(m)) {
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    cout << ans << '\n';
}