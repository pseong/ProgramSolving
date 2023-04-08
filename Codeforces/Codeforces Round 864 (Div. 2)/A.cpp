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

int n, m;
bool ok(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
    else return false;
}

void solve(int CASE) {
    cin >> n >> m;
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << min(ok(x-1, y) + ok(x+1, y) + ok(x, y-1) + ok(x, y+1), ok(a-1, b) + ok(a+1, b) + ok(a, b-1) + ok(a, b+1)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}