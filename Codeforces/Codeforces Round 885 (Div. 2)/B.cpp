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
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    vector<vector<int>> col(k + 1);
    for (int i=1; i<=k; i++) col[i].push_back(0);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        col[v[i]].push_back(i);
    }
    for (int i=1; i<=k; i++) col[i].push_back(n + 1);
    int ans = n;
    for (int i=1; i<=k; i++) {
        vector<int> q;
        for (int j=1; j<(int)col[i].size(); j++) {
            q.push_back(col[i][j] - col[i][j-1] - 1);
        }
        srt(q);
        q.back() = q.back() / 2;
        srt(q);
        ans = min(ans, q.back());
    }
    cout << ans << '\n';
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