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

const ll mod = 998244353;
ll inv = 499122177;
ll s = 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<ll, ll> cnt;
    ll pw = 1;
    ll d = 0;
    for (int i=0; i<n; i++) {
        int W;
        cin >> W;
        if (W == 1) {
            int x;
            cin >> x;
            cnt[x + d] += s;
            cnt[x + d] %= mod;
        }
        else if (W == 2) {
            int x;
            cin >> x;
            d += x;
        }
        else {
            if (d == 0) {
                pw = (pw * 2) % mod;
                s = s * inv % mod;
            }
            else if (d <= 200000) {
                for (int i=d+200000; i>d; i--) {
                    cnt[i + d] += cnt[i];
                    cnt[i + d] %= mod;
                }
                d *= 2;
            }
        }
        while (cnt.size() && cnt.begin()->first < d) cnt.erase(cnt.begin());
    }
    ll ans = 0;
    for (auto [x, y] : cnt) {
        if (x > d) ans += y;
        ans %= mod;
    }
    cout << ans * pw % mod<< '\n';
}