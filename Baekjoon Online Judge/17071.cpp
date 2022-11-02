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

int chk[2][505050];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<2; i++) {
        for (int j=0; j<505050; j++) {
            chk[i][j] = -1;
        }
    }
    queue<int> q;
    q.push(n);
    chk[0][n] = 0;
    int cnt = 0;
    while (q.size()) {
        cnt++;
        int t = q.size();
        while (t--) {
            int a = q.front();
            q.pop();
            if (a - 1 >= 0 && chk[cnt % 2][a - 1] == -1) {
                chk[cnt % 2][a - 1] = cnt;
                q.push(a - 1);
            }
            if (a + 1 <= 500000 && chk[cnt % 2][a + 1] == -1) {
                chk[cnt % 2][a + 1] = cnt;
                q.push(a + 1);
            }
            if (a * 2 <= 500000 && chk[cnt % 2][a * 2] == -1) {
                chk[cnt % 2][a * 2] = cnt;
                q.push(a * 2);
            }
        }
    }
    int go = 0;
    while (k <= 500000) {
        k += go;
        if (chk[go % 2][k] != -1 && chk[go % 2][k] <= go) {
            cout << go << '\n';
            return 0;
        }
        go++;
    }
    cout << -1 << '\n';
}