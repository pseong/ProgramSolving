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

int v[3][101010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=2; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            v[i][j] = s[j-1] - '0';
        }
    }
    queue<pi> q;
    q.push({1, 1});
    v[1][1] = 0;
    int cnt = 0;
    while (q.size()) {
        cnt++;
        int t = q.size();
        while (t--) {
            auto [x, y] = q.front();
            q.pop();
            if (y < cnt) continue;
            vector<pi> lst{{x, y - 1}, {x, y + 1}, {x^1^2, y + k}};
            for (auto [a, b] : lst) {
                if (b < cnt) continue;
                if (b > n) {
                    cout << 1 << '\n';
                    return 0;
                }
                if (v[a][b] == 0) continue;
                v[a][b] = 0;
                q.push({a, b});
            }
        }
    }
    cout << 0 << '\n';
}