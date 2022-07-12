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

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> chk(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (n%2 == 1) {
                if (i == n/2 && j == n/2) continue;
            }
            if (chk[i][j]) continue;
            int cnt[2]{ 0 };
            cnt[s[i][j]-'0']++;
            cnt[s[j][n-1-i]-'0']++;
            cnt[s[n-1-j][i]-'0']++;
            cnt[s[n-1-i][n-1-j]-'0']++;

            chk[i][j] = 1;
            chk[j][n-1-i] = 1;
            chk[n-1-j][i] = 1;
            chk[n-1-i][n-1-j] = 1;

            ans += min(cnt[0], cnt[1]);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}