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

vector<int> adj[20202];
int d[20202], sd[20202], finished[20202];
int id, sccId;
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
        sccId++;
        while (true) {
            int t = st.top();
            st.pop();
            sd[t] = sccId;
            finished[t] = true;
            if (t == x) break;
        }
    }
    return parent;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        int not_a;
        int not_b;
        if (a < 0) {
            not_a = (-a)*2;
            a = (-a)*2 + 1;
        }
        else {
            not_a = a*2 + 1;
            a = a*2;
        }
        if (b < 0) {
            not_b = (-b)*2;
            b = (-b)*2 + 1;
        }
        else {
            not_b = b*2 + 1;
            b = b*2;
        }
        adj[not_a].push_back(b);
        adj[not_b].push_back(a);
    }
    for (int i=2; i<=n*2+1; i++) {
        if (d[i] == 0) dfs(i);
    }
    for (int i=2; i<=n+1; i+=2) {
        if (sd[i] == sd[i+1]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';

    vector<pi> vec;
    for (int i=2; i<=n*2+1; i++) {
        vec.push_back({sd[i], i});
    }
    sort(vec.begin(), vec.end(), greater<pi>());

    vector<int> ans(n+1, -1);
    for (int i=0; i<(int)vec.size(); i++) {
        int x = vec[i].second;
        if (ans[x/2] == -1) {
            if (x%2 == 0) {
                ans[x/2] = 0;
            }
            else {
                ans[x/2] = 1;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (ans[i] == -1) cout << 0 << ' ';
        else cout << ans[i] << ' ';
    }
}