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

int x;

int cal(int m) {
    int two = 0;
    int five = 0;
    for (int i=2; i<=m; i*=2) two += m/i;
    for (int i=5; i<=m; i*=5) five += m/i;
    return min(two, five);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> x;
    int lo = 1;
    int hi = 1e9;
    int ans = -1;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        int c = cal(m);
        if (c >= x) {
            if (c == x) ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << '\n';
}