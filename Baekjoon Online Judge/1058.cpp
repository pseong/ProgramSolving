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

vector<int> adj[60];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            if (s[j-1] == 'Y') {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        vector<int> chk(n + 1);
        queue<int> q;
        q.push(i);
        chk[i] = 1;
        int cnt = -1;
        for (int k=0; k<3; k++) {
            int t = q.size();
            while (t--) {
                int x = q.front();
                cnt++;
                q.pop();
                for (int y : adj[x]) {
                    if (chk[y]) continue;
                    chk[y] = 1;
                    q.push(y);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}