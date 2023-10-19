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

const ll p = 998244353;

void solve(int CASE) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 1;
    vector<ll> ans {0, 1};
    for (int i=1; i<=n; i++) {
        if (i == n || s[i] != s[i-1]) {
            if (cnt == 1) continue;
            ans[0] += cnt - 1;
            ans[1] *= cnt;
            ans[1] %= p;
            cnt = 1;
        }
        else cnt++;
    }
    for (int i=1; i<=ans[0]; i++) {
        ans[1] *= i;
        ans[1] %= p;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}