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
    int x, k, n;
    cin >> n >> k >> x;
    if (x != 1) {
        yes();
        cout << n << '\n';
        for (int i=1; i<=n; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }
    else {
        if (k == 1) no();
        else if (k == 2) {
            if (n%2 == 0) {
                yes();
                cout << n/2 << '\n';
                for (int i=1; i<=n/2; i++) {
                    cout << 2 << ' ';
                }
                cout << '\n';
            }
            else no();
        }
        else {
            if (n == 1) no();
            else {
                if (n%2) {
                    yes();
                    cout << (n-3)/2 + 1 << '\n';
                    cout << 3 << ' ';
                    for (int i=1; i<=(n-3)/2; i++) {
                        cout << 2 << ' ';
                    }
                    cout << '\n';
                }
                else {
                    yes();
                    cout << n/2 << '\n';
                    for (int i=1; i<=n/2; i++) {
                        cout << 2 << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
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