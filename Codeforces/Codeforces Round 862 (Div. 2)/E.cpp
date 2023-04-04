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
int n, v[101010], chk[101010];

map<int, int> cnt(int s, int no, int no2) {
    map<int, int> c;
    queue<int> q;
    q.push(s);
    chk[s] = 1;
    while (q.size()) {
        int x = q.front();
        c[v[x]]++;
        q.pop();
        for (int y : adj[x]) {
            if (chk[y]) continue;
            if (no == y || no2 == y) continue;
            chk[y] = 1;
            q.push(y);
        }
    }
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pi> in(n-1);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        in[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto it=mp.rbegin(); it!=mp.rend(); it++) {
        if (it->second >= 3) {
            for (int i=0; i<n-1; i++) {
                cout << it->first << '\n';
            }
            return 0;
        }
        else if (it->second == 2) {
            vector<int> w;
            for (int i=1; i<=n; i++) {
                if (v[i] == it->first) w.push_back(i);
            }
            int x = w[0];
            int y = w[1];
            vector<int> hist(n + 1, -1);
            queue<int> q;
            q.push(x);
            hist[x] = 0;
            while (q.size()) {
                int a = q.front();
                q.pop();
                for (int b : adj[a]) {
                    if (hist[b] != -1) continue;
                    hist[b] = a;
                    q.push(b);
                }
            }
            vector<int> log;
            int g = y;
            while (g != x) {
                log.push_back(g);
                g = hist[g];
            }
            reverse(log.begin(), log.end());
            map<int, int> cntX = cnt(x, log.front(), 0);
            map<int, int> cntY = cnt(log.front(), x, 0);
            map<pi, int> as;
            int nowX = 0, nowY = 0;
            for (auto [f, s] : cntX) {
                if (s >= 2) {
                    nowX = f;
                }
            }
            for (auto [f, s] : cntY) {
                if (s >= 2) {
                    nowY = f;
                }
            }
            for (int i=0; i<101010; i++) {
                chk[i] = 0;
            }
            int prv = x;
            for (int i=0; i<(int)log.size(); i++) {
                int nxt = log[i];
                int r = prv;
                int c = nxt;
                if (r > c) swap(r, c);
                as.insert({{r, c}, max(nowX, nowY)});
                if (i >= (int)log.size() - 1) break;
                map<int, int> m = cnt(log[i], prv, log[i+1]);
                for (auto [f, s] : m) {
                    cntY[f] -= s;
                    cntX[f] += s;
                    if (cntX[f] >= 2 && f > nowX) nowX = f;
                }
                if (nowY != 0 && cntY[nowY] < 2) {
                    auto it2 = cntY.find(nowY);
                    while (it2 != cntY.begin() && it2->second < 2) it2--;
                    if (it2->second >= 2) nowY = it2->first;
                    else nowY = 0;
                }
                prv = log[i];
            }   
            for (int i=0; i<n-1; i++) {
                auto it2 = as.find(in[i]);
                if (it2 != as.end()) cout << it2->second << '\n';
                else cout << it->first << '\n';
            }
            return 0;
        }
    }
    for (int i=0; i<n-1; i++) {
        cout << 0 << '\n';
        return 0;
    }
}