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
    
    int n, m, k;
    cin >> n >> m >> k;
    int l = k - 1;
    int r = n - k;
    int ans = 0;
    while (true) {
        if (l) {
            if (l%2) {
                l /= 2;
                r /= 2;
            }
            else {
                l = (l-1) / 2;
                r = (r+1) / 2;
            }
        }
        else {
            if (m) {
                if (r == 0) break;
                m--;
                r /= 2;
            }
            else break;
        }
        ans++;
    }
    cout << ans << '\n';
}