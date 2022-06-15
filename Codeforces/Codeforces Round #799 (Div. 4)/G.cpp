#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        vector<ll> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        int cnt = 0;
        int ans = 0;
        for (int i=0; i<n-1; i++) {
            if (v[i] < v[i+1]*2) {
                cnt++;
                ans += (cnt >= k);
            }
            else {
                cnt = 0;
            }
        }
        cout << ans << '\n';
    }
}