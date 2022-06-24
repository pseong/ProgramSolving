#include <bits/stdc++.h>
#define int long long
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
    vector<int> v(n+1);
    for (int i=1; i<n; i++) {
        cout << "? ";
        for (int j=1; j<=n-1; j++) {
            cout << 1 << ' ';
        }
        cout << 1 + i << endl;
        int r; cin >> r;
        v[r] = i;
    }
    for (int i=1; i<n; i++) {
        cout << "? ";
        for (int j=1; j<=n-1; j++) {
            cout << n << ' ';
        }
        cout << n - i << endl;
        int r; cin >> r;
        v[r] = -i;
    }
    int m = *min_element(v.begin()+1, v.end());
    m = 1 - m;
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << v[i] + m << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}