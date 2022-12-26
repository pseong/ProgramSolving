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
    
    int n, k;
    cin >> n >> k;
    int h = 0, m = 0, s = 0;
    int ans = 0;
    while (true) {
        bool ok = false;
        if (h % 10 == k) ok = true;
        if (h / 10 % 10 == k) ok = true;
        if (m % 10 == k) ok = true;
        if (m / 10 % 10 == k) ok = true;
        if (s % 10 == k) ok = true;
        if (s / 10 % 10 == k) ok = true;
        if (ok) ans++;
        if ((h == n && m == 59 && s == 59)) break;
        s++;
        if (s == 60) {
            s = 0;
            m++;
        }
        if (m == 60) {
            m = 0;
            h++;
        }
    }
    cout << ans << '\n';
}