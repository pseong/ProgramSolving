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

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i] >> v[i];
    }
    vector<int> ans{0, (int)1e9};
    for (int k=0; k<(1<<n); k++) {
        vector<int> chk(m), cnt{0, 0};
        for (int i=0; i<n; i++) {
            if (k & (1<<i)) {
                cnt[1]++;
                for (int j=0; j<m; j++) {
                    if (v[i][j] == 'Y') chk[j] = 1;
                }
            }
        }
        for (int j=0; j<m; j++) {
            if (chk[j]) cnt[0]++;
        }
        if (ans[0] == cnt[0]) {
            ans[1] = min(ans[1], cnt[1]);
        }
        else if (ans[0] < cnt[0]) {
            ans[0] = cnt[0];
            ans[1] = cnt[1];
        }
    }
    if (ans[0] == 0) cout << -1 << '\n';
    else cout << ans[1] << '\n';
}