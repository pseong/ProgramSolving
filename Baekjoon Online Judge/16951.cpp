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
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int ans = n;
    for (int i=0; i<n; i++) {
        auto tmp = v;
        int cnt = 0;
        for (int j=i+1; j<n; j++) {
            if (tmp[j] - tmp[j-1] != k) {
                cnt++;
                tmp[j] = tmp[j-1] + k;
            }
        }
        for (int j=i-1; j>=0; j--) {
            if (tmp[j+1] - tmp[j] != k) {
                cnt++;
                tmp[j] = tmp[j + 1] - k;
            }
        }
        for (int i=0; i<n; i++) {
            if (tmp[i] < 1) goto g;
        }
        ans = min(ans, cnt);
        g:
        continue;
    }
    cout << ans << '\n';
}