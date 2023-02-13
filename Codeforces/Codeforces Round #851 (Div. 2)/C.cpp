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
        no();
        return;
    }
    yes();
    int x = (5*n+1)/2 - n + 1;
    int a = 1;
    int b = x - 1;
    for (int i=0; i<(n+1)/2; i++) {
        cout << a + i << ' ' << b + i << '\n';
    }
    a = (n+1)/2 + 1;
    b = x + 1 - a;
    for (int i=0; i<n/2; i++) {
        cout << a + i << ' ' << b + i << '\n';
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