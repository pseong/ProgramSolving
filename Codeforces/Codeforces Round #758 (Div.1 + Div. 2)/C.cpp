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

vector<int> adj[101010];
bool chk[101010];

void dfs(int x) {
    chk[x] = 1;
    for (int y : adj[x]) if (chk[y] == 0) dfs(y);
}

void solve() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        adj[i].clear();
    }
    vector<pi> A(n+1), B(n+1);
    for (int i=1; i<=n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for (int i=1; i<=n; i++) {
        cin >> B[i].first;
        B[i].second = i;
    }
    sort(A.begin()+1, A.end());
    sort(B.begin()+1, B.end());
    for (int i=1; i<n; i++) {
        adj[A[i].second].push_back(A[i+1].second);
        adj[B[i].second].push_back(B[i+1].second);
    }
    memset(chk, 0, sizeof chk);
    dfs(A[n].second);
    dfs(B[n].second);
    for (int i=1; i<=n; i++) {
        cout << chk[i];
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}