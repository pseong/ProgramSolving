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
    
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> chk(n + 1, vector<int>(n + 1));
    queue<pi> q;
    q.push({1, 1});
    chk[1][1] = 1;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        vector<pi> lst{{x + v[x][y], y}, {x, y + v[x][y]}};
        for (auto [a, b] : lst) {
            if (a < 1 || a > n || b < 1 || b > n) continue;
            if (chk[a][b]) continue;
            chk[a][b] = 1;
            q.push({a, b});
            if (a == n && b == n) {
                cout << "HaruHaru\n";
                return 0;
            }
        }
    }
    cout << "Hing\n";
}