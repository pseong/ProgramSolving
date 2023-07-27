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

    int n;
    cin >> n;
    vector<int> v(n + 2);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        if (v[i] == 2) {
            int l = i;
            int r = i;
            while (v[l] != 0) v[l] = 2, l--;
            while (v[r] != 0) v[r] = 2, r++;
            i = r - 1;
        }
    }
    vector<int> w{ 0 };
    for (int i=1; i<=n; i++) {
        if (v[i] == 0) w.push_back(0);
        else {
            w.push_back(v[i]);
            int j = i;
            while (j <= n && v[i] == v[j]) j++;
            i = j - 1;
        }
    }
    n = w.size() - 1;
    vector<int> d(n + 2);
    d[0] = 1;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (w[i] == 1) {
            ans++;
            d[i] = 1;
            if (!d[i-1]) d[i-1] = 1;
            else d[i+1] = 1;
        }
        else if (w[i] == 2) {
            ans++;
            d[i] = 1;
            d[i-1] = 1;
            d[i+1] = 1;
        }
    }
    for (int i=1; i<=n; i++) if (!d[i]) ans++;
    cout << ans << '\n';
}