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

void solve(int CASE) {
    int n, x, y;
    cin >> n >> x >> y;
    if (y == 0) swap(x, y);
    if (x != 0) {
        cout << -1 << '\n';
        return;
    }
    if (y == 0 || (n-1)%y != 0) {
        cout << -1 << '\n';
        return;
    }
    for (int i=0; i<y; i++) cout << 1 << ' ';
    for (int i=y+2; i<=n; i+=y) {
        for (int j=0; j<y; j++) cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

#if TEST
    freopen("/Users/macrent/ProgramSolving/input.txt", "r", stdin);
#endif

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}