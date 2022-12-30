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
    vector<int> w(n), v(n);
    for (int i=0; i<n; i++) {
        cin >> w[i];
        v[i] = i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    do {
        int now = 500;
        bool ok = true;
        for (int i=0; i<n; i++) {
            now += w[v[i]];
            now -= k;
            if (now < 500) ok = false;
        }
        if (ok) ans++;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}