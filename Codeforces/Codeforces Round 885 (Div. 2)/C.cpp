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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    int d = -1;
    for (int i=1; i<=n; i++) {
        int x = a[i];
        int y = b[i];
        if (x == 0 && y == 0) continue;
        int idx = 0;
        while (true) {
            if (x == 0) {
                if (d == -1) d = idx % 3;
                else if (d != idx % 3) {
                    no();
                    return;
                }
                break;
            }
            y %= (x*2);
            idx++;
            int z = abs(x - y);
            x = y;
            y = z;
        }
    }
    yes();
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