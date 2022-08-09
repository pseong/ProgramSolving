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
    vector<int> ans(n);
    int cur = n-1;
    int x = 0;
    while (cur > x*x) x++;
    while (cur > 0) {
        while (cur <= (x-1)*(x-1)) x--;
        int s = x*x - cur;
        for (int i=0; i<=cur-s; i++) {
            ans[s+i] = cur - i;
        }
        cur = s - 1;
    }
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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