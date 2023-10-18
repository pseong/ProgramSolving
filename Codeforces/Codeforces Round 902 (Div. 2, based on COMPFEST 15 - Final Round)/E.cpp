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
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n + 1), in(n + 1), chk(n + 1, -1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        in[v[i]]++;
    }
    queue<int> q;
    for (int i=1; i<=n; i++) if (!in[i]) q.push(i);
    while (q.size()) {
        int x = q.front();
        q.pop();
        chk[x] = 1;
        if (chk[v[x]] == -1) {
            chk[v[x]] = 0;
            if (--in[v[v[x]]] == 0) q.push(v[v[x]]);
        }
    }
    for (int i=1; i<=n; i++) {
        if (chk[i] == -1) {
            vector<int> x;
            int g = i;
            while (chk[g] == -1) {
                chk[g] = -2;
                x.push_back(g);
                g = v[g];
            }
            if (x.size() % 2) {
                cout << -1 << '\n';
                return 0;
            }
            for (int i=0; i<x.size(); i++) {
                chk[x[i]] = i % 2;
            }
        }
    }
    vector<int> ans;
    for (int i=1; i<=n; i++) if (chk[i] == 1) ans.push_back(v[i]);
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}