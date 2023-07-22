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

vector<vector<int>> dp;
string s;
vector<int> v;

int cmp(int x, int y) {
    if (x > y) return 0;
    else if (x < y) return 2;
    else return 1;
}

int DP(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x + 1 == y) {
        if (v[x] != v[y]) return 2;
        else return 1;
    }
    int r1 = (DP(x + 2, y) != 1 ? DP(x + 2, y) : cmp(v[x], v[x + 1]));
    int r2 = (DP(x + 1, y - 1) != 1 ? DP(x + 1, y - 1) : cmp(v[x], v[y]));
    int r3 = (DP(x, y - 2) != 1 ? DP(x, y - 2) : cmp(v[y], v[y - 1]));
    int r4 = (DP(x + 1, y - 1) != 1 ? DP(x + 1, y - 1) : cmp(v[y], v[x]));
    return dp[x][y] = max(min(r1, r2), min(r3, r4));
}

void solve(int CASE) {
    string s;
    cin >> s;
    int n = s.size();
    v.resize(n + 1);
    for (int i=1; i<=n; i++) v[i] = s[i-1]-'a';
    dp.assign(n + 1, vector<int>(n + 1, -1));
    if (DP(1, n) == 0) cout << "Bob\n";
    else if (DP(1, n) == 2) cout << "Alice\n";
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