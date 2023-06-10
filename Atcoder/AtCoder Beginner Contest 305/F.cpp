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
    vector<vector<int>> adj(n + 1);
    vector<int> chk(n + 1), par(n + 1), idx(n + 1);
    chk[1] = 1;
    int now = 1;
    while (true) {
        int k;
        cin >> k;
        if (k == -1) break;
        adj[now].clear();
        for (int i=0; i<k; i++) {
            int a;
            cin >> a;
            if (a != par[now]) adj[now].push_back(a);
        }
        while (idx[now] < adj[now].size() && chk[adj[now][idx[now]]]) idx[now]++;
        if (idx[now] < adj[now].size()) {
            cout << adj[now][idx[now]] << endl;
            par[adj[now][idx[now]]] = now;
            now = adj[now][idx[now]];
            chk[now] = 1;
            if (now == n) break;
        }
        else {
            cout << par[now] << endl;
            now = par[now];
        }
    }
}