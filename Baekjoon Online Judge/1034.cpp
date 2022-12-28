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
        cin >> v[i];
    }
    int k;
    cin >> k;
    int ans = 0;
    for (int i=0; i<n; i++) {
        auto t = v;
        vector<int> c(m);
        int cnt = 0;
        for (int j=0; j<m; j++) {
            if (v[i][j] == '0') c[j] = 1, cnt++;
        }
        if (cnt > k || cnt < k && (k - cnt) % 2 != 0) continue;
        int res = 0;
        for (int a=0; a<n; a++) {
            bool ok = true;
            for (int b=0; b<m; b++) {
                if ((v[a][b] - '0') ^ c[b] == 0) ok = false;
            }
            if (ok) res++;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}