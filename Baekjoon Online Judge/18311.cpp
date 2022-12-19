#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

ll n, k, v[202020];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[n*2+1-i] = v[i];
    }
    ll sum = 0;
    for (int i=1; i<=n*2; i++) {
        sum += v[i];
        if (k < sum) {
            if (i <= n) cout << i << '\n';
            else cout << n*2 + 1 - i << '\n';
            return 0;
        }
    }
}