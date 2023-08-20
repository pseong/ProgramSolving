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

int dist[26][26][50505];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    string s;
    int m;
    cin >> s >> m;
    int n = s.size() - 1;
    vector<int> mp[26][26];
    for (int i=0; i<n; i++) {
        mp[s[i]-'a'][s[i+1]-'a'].push_back(i + 1);
    }
    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            for (int k=0; k<50505; k++) dist[i][j][k] = inf;
            int vis[26][26]{};
            vis[i][j] = 1;
            queue<int> q;
            for (auto x : mp[i][j]) {
                q.push(x);
                dist[i][j][x] = 0;
            }
            while (q.size()) {
                int x = q.front();
                q.pop();
                if (x > 1 && dist[i][j][x-1] == inf) {
                    dist[i][j][x-1] = dist[i][j][x] + 1;
                    q.push(x - 1);
                }
                if (x < n && dist[i][j][x+1] == inf) {
                    dist[i][j][x+1] = dist[i][j][x] + 1;
                    q.push(x + 1);
                }
                int l = s[x-1] - 'a', r = s[x] - 'a';
                if (vis[l][r] == 0) {
                    vis[l][r] = 1;
                    for (int y : mp[l][r]) {
                        if (dist[i][j][y] == inf) {
                            dist[i][j][y] = dist[i][j][x] + 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        int ans = abs(x - y);
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                ans = min(ans, dist[i][j][x] + dist[i][j][y] + 1);
            }
        }
        cout << ans << '\n';
    }
}