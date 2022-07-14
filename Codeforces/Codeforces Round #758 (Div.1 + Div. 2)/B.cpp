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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a-b) > 1 || a+b > n-2) {
        cout << -1 << '\n';
        return;
    }
    if (a >= b) {
        int cnt = a + b;
        int i = 1;
        for (; i<=n-cnt-1; i++) {
            cout << i << ' ';
        }
        int j = n;
        int dir = 1;
        while (i <= j) {
            if (dir) {
                cout << j << ' ';
                j--;
            }
            else {
                cout << i << ' ';
                i++;
            }
            dir ^= 1;
        }
        cout << '\n';
    }
    else {
        int cnt = a + b;
        int j = n;
        for (; j >= 2+cnt; j--) {
            cout << j << ' ';
        }
        int i = 1;
        int dir = 1;
        while (i <= j) {
            if (dir) {
                cout << i << ' ';
                i++;
            }
            else {
                cout << j << ' ';
                j--;
            }
            dir ^= 1;
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}