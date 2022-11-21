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

vector<int> adj[100];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans(n + 1);
    int mn = 50;
    for (int i=1; i<=n; i++) {
        int cnt = -1;
        vector<int> chk(n + 1);
        chk[i] = 1;
        queue<int> q;
        q.push(i);
        while (q.size()) {
            cnt++;
            int t = q.size();
            while (t--) {
                int x = q.front();
                q.pop();
                for (int y : adj[x]) {
                    if (chk[y]) continue;
                    chk[y] = 1;
                    q.push(y);
                }
            }
        }
        bool ok = true;
        for (int i=1; i<=n; i++) {
            if (chk[i] == 0) ok = false;
        }
        if (ok) ans[i] = cnt;
        mn = min(mn, ans[i]);
    }
    vector<int> a;
    for (int i=1; i<=n; i++) {
        if (ans[i] == mn) a.push_back(i);
    }
    sort(a.begin(), a.end());
    cout << mn << ' ' << a.size() << '\n';
    for (int x : a) {
        cout << x << ' ';
    }
}