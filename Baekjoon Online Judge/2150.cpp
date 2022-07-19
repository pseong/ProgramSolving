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

vector<int> adj[10101];
vector<vector<int>> SCC;
int id, d[10101], finished[10101];
stack<int> st;

int dfs(int x) {
    d[x] = ++id;
    st.push(x);

    int parent = d[x];
    for (int y : adj[x]) {
        if (d[y] == 0) parent = min(parent, dfs(y));
        else if (!finished[y]) parent = min(parent, d[y]);
    }

    if (parent == d[x]) {
        vector<int> scc;
        while (true) {
            int t = st.top();
            st.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x) break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, e;
    cin >> n >> e;
    for (int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i=1; i<=n; i++) {
        if (d[i] == 0) dfs(i);
    }

    for (int i=0; i<(int) SCC.size(); i++) {
        srt(SCC[i]);
    }
    srt(SCC);
    
    cout << SCC.size() << '\n';
    for (int i=0; i<(int) SCC.size(); i++) {
        for (int x : SCC[i]) {
            cout << x << ' ';
        }
        cout << "-1\n";
    }
}