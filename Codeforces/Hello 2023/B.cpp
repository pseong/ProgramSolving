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
    if (n%2 == 0) {
        yes();
        for (int i=0; i<n; i++) {
            if (i%2 == 0) cout << -1 << ' ';
            else cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
    if (n == 3) {
        no();
        return;
    }
    yes();
    int b = n/2;
    int a = -(n/2-1);
    for (int i=0; i<n; i++) {
        if (i%2 == 0) cout << a << ' ';
        else cout << b << ' ';
    }
    cout << '\n';
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