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

int cnt[5050505];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int g, x;
        cin >> g >> x;
        cnt[x] += g;
    }
    int now = 0;
    int r = -1;
    int ans = 0;
    for (int l=0; l<=1000000; l++) {
        while (r - l < k*2) {
            r++;
            now += cnt[r];
        }
        ans = max(ans, now);
        now -= cnt[l];
    }
    cout << ans << '\n';
}