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
    int ans = 0;
    vector<int> v{0, 0, 0, 0};
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            v[0] = min(v[0], b);
            v[1] = max(v[1], b);
        }
        if (b == 0) {
            v[2] = min(v[2], a);
            v[3] = max(v[3], a);
        }
    }
    cout << 2 * (abs(v[0]) + v[1] + abs(v[2]) + v[3]) << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}