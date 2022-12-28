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

    int ff, fs, sf, ss;
    cin >> ff >> fs >> sf >> ss;
    if (ff == 0 && fs == 0) {
        cout << ss + (sf ? 1 : 0) << '\n';
        return 0;
    }
    int ans = 0;
    if (ff) ans += ff;
    if (fs == 0) {
        cout << ans << '\n';
        return 0;
    }
    ans++, fs--;
    if (ss) ans += ss;
    if (fs >= sf) {
        cout << ans + sf * 2 << '\n';
    }
    else if (fs < sf) {
        cout << ans + fs * 2 + 1 << '\n';
    }
}