#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
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
    int n;
    cin >> n;
    vector<string> v(n);
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        for (int j=0; j<n; j++) {
            if (v[i][j] == '1') adj[j].push_back(i);
        }
    }
    for (int i=0; i<n; i++) {
        vector<int> chk(n);
        queue<int> q;
        q.push(i);
        chk[i] = 1;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (chk[y]) continue;
                chk[y] = 1;
                q.push(y);
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (chk[i]) ans.push_back(i);
        }
        cout << ans.size() << ' ';
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
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