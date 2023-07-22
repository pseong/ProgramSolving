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

vector<vector<vector<int>>> dp;

string s;
vector<int> v;
int DP(int x, int y, int c) {
    if (dp[x][y][c] != -1) return dp[x][y][c];
    if (x + 1 == y) {
        if (v[x] != v[y]) return 2;
        else return c;
    }
    int res1 = 2;
    int res2 = 2;

    if (v[x] > v[x+1]) res1 = min(res1, DP(x + 2, y, 0));
    else if (v[x] < v[x+1]) res1 = min(res1, DP(x + 2, y, 2));
    else res1 = min(res1, DP(x + 2, y, c));

    if (v[x] > v[y]) res1 = min(res1, DP(x + 1, y - 1, 0));
    else if (v[x] < v[y]) res1 = min(res1, DP(x + 1, y - 1, 2));
    else res1 = min(res1, DP(x + 1, y - 1, c));

    if (v[y] > v[y-1]) res2 = min(res2, DP(x, y - 2, 0));
    else if (v[y] < v[y-1]) res2 = min(res2, DP(x, y - 2, 2));
    else res2 = min(res2, DP(x, y - 2, c));

    if (v[x] < v[y]) res2 = min(res2, DP(x + 1, y - 1, 0));
    else if (v[x] > v[y]) res2 = min(res2, DP(x + 1, y - 1, 2));
    else res2 = min(res2, DP(x + 1, y - 1, c));

    return dp[x][y][c] = max(res1, res2);
}

void solve(int CASE) {
    string s;
    cin >> s;
    int n = s.size();
    v.resize(n + 1);
    for (int i=1; i<=n; i++) v[i] = s[i-1]-'a';
    dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));
    if (DP(1, n, 1) == 0) cout << "Bob\n";
    else if (DP(1, n, 1) == 2) cout << "Alice\n";
    else cout << "Draw\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

#if TEST
    freopen("/Users/macrent/ProgramSolving/input.txt", "r", stdin);
#endif

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}