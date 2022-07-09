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
    int n; cin >> n;
    vector<int> q(n+1, -1);
    vector<int> ans(n+1, -1);
    int x = -1, y = -1;
    for (int i=3; i<=n; i++) {
        cout << "? " << i-2 << ' ' << i-1 << ' ' << i << endl;
        cin >> q[i];
        if (q[i-1] != -1 && q[i] != q[i-1]) {
            if (q[i] == 0) {
                ans[i] = 0;
                ans[i-3] = 1;
            }
            else {
                ans[i] = 1;
                ans[i-3] = 0;
            }
            x = i;
            y = i-3;
            break;
        }
    }
    for (int i=1; i<=n; i++) {
        if (ans[i] == -1) {
            cout << "? " << x << ' ' << y << ' ' << i << endl;
            int r;
            cin >> r;
            if (r == 0) {
                ans[i] = 0;
            }
            else ans[i] = 1;
        }
    }
    vector<int> an;
    for (int i=1; i<=n; i++) {
        if (ans[i] == 0) an.push_back(i);
    }
    cout << "! " << an.size() << ' ';
    for (int x : an) {
        cout << x << ' ';
    }
    cout << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
}