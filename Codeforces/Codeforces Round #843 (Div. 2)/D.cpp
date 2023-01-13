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
 
vector<int> adj[606060], factors[303030];
const int bias = 300000;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i=1; i<=300000; i++) {
        int go = i;
        for (int j=2; j*j<=go; j++) {
            if (go % j == 0) {
                factors[i].push_back(j);
                while (go % j == 0) go /= j;
            }
        }
        if (go != 1) factors[i].push_back(go);
    }
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        for (int x : factors[v[i]]) {
            adj[i+bias].push_back(x);
            adj[x].push_back(i+bias);
        }
    }
    int s, e;
    cin >> s >> e;
    s += bias;
    e += bias;
    queue<int> q;
    vector<int> hist(606060, -1);
    hist[s] = 0;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (hist[y] != -1) continue;
            hist[y] = x;
            q.push(y);
        }
    }
    if (hist[e] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans;
    int go = e;
    while (go) {
        ans.push_back(go);
        go = hist[go];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() / 2 + 1 << '\n';
    for (int i=0; i<(int)ans.size(); i+=2) {
        cout << ans[i] - bias << ' ';
    }
    cout << '\n';
}