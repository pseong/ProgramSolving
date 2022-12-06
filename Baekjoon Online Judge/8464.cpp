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

const int MAX = 200000;
vector<int> primes;
int chk[MAX+1], sign[MAX+1];

ll cal(ll x) {
    ll res = 0;
    for (ll i=2; i*i<=x; i++) {
        res += sign[i] * (x / (i * i));
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<=MAX; i++) {
        if (chk[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<=MAX; j+=i) {
                chk[j] = 1;
            }
        }
    }

    memset(sign, -1, sizeof sign);
    sign[1] = 0;
    for (int i=2; i<=MAX; i++) {
        for (ll j=2; j*j<=i; j++) {
            if (i % (j * j) == 0) {
                sign[i] = 0;
                break;
            }
        }
        if (sign[i] == 0) continue;
        int cnt = 0;
        int x = i;
        for (int j=0; j<(int)primes.size() && primes[j] <= x; j++) {
            if (x % primes[j] == 0) {
                cnt++;
                x /= primes[j];
            }
        }
        if (cnt%2 == 1) sign[i] = 1;
    }

    ll k;
    cin >> k;

    ll lo = 1;
    ll hi = k*4;
    ll ans = hi;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cal(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << '\n';
}