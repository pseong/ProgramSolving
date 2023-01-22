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

int chk[101010];

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<vector<int>> div(n);
    for (int i=0; i<n; i++) {
        int go = v[i];
        for (int j=1; j*j<=v[i]; j++) {
            if (v[i] % j == 0) {
                div[i].push_back(j);
                if (j*j != v[i]) div[i].push_back(v[i]/j);
            }
        }
    }
    int r = -1;
    int cnt = 0;
    int ans = 1e9;
    for (int l=0; l<n; l++) {
        while (r+1<n && cnt<m) {
            r++;
            for (int x : div[r]) {
                if (x > m) continue;
                if (chk[x]++ == 0) cnt++;
            }
        }
        if (cnt == m) ans = min(ans, v[r] - v[l]);
        for (int x : div[l]) {
            if (x > m) continue;
            if (--chk[x] == 0) cnt--;
        }
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}