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

void solve(int CASE) {
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l + 1);
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i=1; i<=l; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> b[i][j];
        }
    }
    vector<vector<int>> prev(n + 1, vector<int>(m + 1));
    for (int t=l; t>=2; t--) {
        vector<vector<int>> now(n + 1, vector<int>(m + 1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (prev[i][j] == 0 && b[i][j] == a[t]) {
                    now[i - 1][j - 1] = 1;
                }
            }
        }
        for (int i=n; i>=1; i--) {
            for (int j=m; j>=1; j--) {
                if (now[i][j]) {
                    now[i - 1][j] = 1;
                    now[i][j - 1] = 1;
                }
            }
        }
        prev = now;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (prev[i][j] == 0 && b[i][j] == a[1]) {
                cout << "T\n";
                return;
            }
        }
    }
    cout << "N\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("C:/dnrseong/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}