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

int query(int x) {
    cout << "? " << x << endl;
    int r;
    cin >> r;
    return r;
}

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    int ans = 0, l = 0;
    for (int i=1; i<=n-k+1; i+=k) {
        ans ^= query(i);
        l = i;
    }
    for (int i=l+1; i<=n-k+1; i++) {
        ans ^= query(i);
    }
    cout << "! " << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}