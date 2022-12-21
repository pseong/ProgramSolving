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

int ans[110][110];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int m = 1;
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            // ans[i-r1][j-c2]
            int k = max(abs(i), abs(j));
            int now = 4*k*k + 4*k + 1;
            int go = k * 2;
            int dx[] {0, -1, 0, 1};
            int dy[] {-1, 0, 1, 0};
            int d = 0;
            int x = k;
            int y = k;
            while (x != i || y != j) {
                x += dx[d];
                y += dy[d];
                now--;
                go--;
                if (go == 0) go = k * 2, d++;
            }
            ans[i-r1][j-c1] = now;
            m = max(m, (int)to_string(now).size());
        }
    }
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            cout << setw(m) << ans[i-r1][j-c1] << ' ';
        }
        cout << '\n';
    }
}