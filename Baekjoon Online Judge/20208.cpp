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

int n, m, h, v[30][30];;
vector<pi> c;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> h;
    int s, e;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) c.push_back({i, j});
            if (v[i][j] == 1) s = i, e = j;
        }
    }
    sort(c.begin(), c.end());
    int ans = 0;
    do {
        int x = s;
        int y = e;
        int hp = m;
        for (int i=0; i<(int)c.size(); i++) {
            hp -= abs(x - c[i].first) + abs(y - c[i].second);
            x = c[i].first;
            y = c[i].second;
            if (hp < 0) break;
            hp += h;
            if (abs(x - s) + abs(y - e) <= hp) {
                if (max(ans, i + 1) == 3) {
                    int ad = 3;
                    ad += ad;
                }
                ans = max(ans, i + 1);
            }
        }
    } while (next_permutation(c.begin(), c.end()));
    cout << ans << '\n';
}