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

int dx[] {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    map<string, int> mp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            queue<tuple<int, int, string>> q;
            q.push({i, j, string(1, v[i][j])});
            mp[string(1, v[i][j])]++;
            int tt = 4;
            while (tt--) {
                int t = q.size();
                while (t--) {
                    auto [a, b, str] = q.front();
                    q.pop();
                    for (int d=0; d<8; d++) {
                        int x = a + dx[d];
                        int y = b + dy[d];
                        x = (x + n) % n;
                        y = (y + m) % m;
                        mp[str + v[x][y]]++;
                        q.push({x, y, str + v[x][y]});
                    }
                }
            }
        }
    }

    for (int i=0; i<k; i++) {
        string s;
        cin >> s;
        cout << mp[s] << '\n';
    }
}