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

ll cal(string s) {
    int n = s.size();
    ll res = 0;
    for (int i=1; i<=n-1; i++) {
        bool ok = false;
        for (int j=i; j<n; j++) {
            if (s[j-i] == s[j]) ok = true;
        }
        if (ok) res += i;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int n = a + b;
    string ans(n, 'a');
    char c = 'b';
    bool ok = false;
    if (a > b) {
        ok = true;
        swap(a, b);
        for (int i=0; i<n; i++) {
            ans[i] = 'b';
        }
        c = 'a';
    }
    int cnt = 0;
    if (b >= 3) {
        ans[0] = c;
        ans[1] = c;
        ans[n-1] = c;
        cnt = 3;
    }
    else if (b == 2) {
        ans[0] = c;
        ans[n-1] = c;
        cnt = 2;
    }
    else if (b == 1) {
        ans[0] = c;
        cnt = 1;
    }
    for (int i=n-3; i>1; i-=2) {
        if (cnt >= b) break;
        ans[i] = c;
        cnt++;
    }
    for (int i=0; i<n; i++) {
        if (cnt < b && ans[i] != c) {
            ans[i] = c;
            cnt++;
        }
    }
    cout << cal(ans) << '\n';
    cout << ans << '\n';
}