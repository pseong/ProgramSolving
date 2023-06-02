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

    int k;
    cin >> k;
    vector<int> v(1<<k);
    for (int i=0; i<(1<<k); i++) {
        cin >> v[i];
    }
    ll ans = 1;
    const ll mod = 998244353;
    for (int j=k; j>=1; j--) {
        int nsz = (1<<(j-1));
        vector<int> v2(nsz, -1);
        int fixed = 0;
        for (int i=0; i<nsz; i++) {
            if (v[i*2] == -1 && v[i*2+1] == -1) {
            }
            else if (v[i*2] == -1 || v[i*2+1] == -1) {
                int left = v[i*2] + v[i*2+1] + 1;
                if (left > nsz) fixed++;
            }
            else {
                if (v[i*2] <= nsz && v[i*2+1] <= nsz) ans *= 0;
                else if (v[i*2] > nsz && v[i*2+1] > nsz) ans *= 0;
                else fixed++;
            }
        }
        int re = nsz - fixed;
        for (int i=0; i<nsz; i++) {
            if (v[i*2] == -1 && v[i*2+1] == -1) {
                ans *= re;
                ans %= mod;
                ans *= 2;
                ans %= mod;
                re--;
            }
            else if (v[i*2] == -1 || v[i*2+1] == -1) {
                int left = v[i*2] + v[i*2+1] + 1;
                if (left <= nsz) {
                    ans *= re;
                    ans %= mod;
                    v2[i] = left;
                    re--;
                }
            }
            else {
                if (v[i*2] <= nsz && v[i*2+1] <= nsz) ans *= 0;
                else if (v[i*2] > nsz && v[i*2+1] > nsz) ans *= 0;
                else v2[i] = (v[i*2] <= nsz) ? v[i*2] : v[i*2+1];
            }
        }
        v = v2;
    }
    cout << ans << '\n';
}