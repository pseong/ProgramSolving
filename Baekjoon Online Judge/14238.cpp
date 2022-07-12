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

int cnt[3], dp[60][60][60][3][3];
string ans;
int n;

bool f(int i, int a, int b, int pprev, int prev) {
    if (dp[i][a][b][pprev][prev]) return false;
    dp[i][a][b][pprev][prev] = 1;
    if (i == n && a == cnt[0] && b == cnt[1]) {
        return true;
    }
    if (i >= n || a > n || b > n) return false;

    ans[i] = 'A';
    if (f(i+1, a+1, b, prev, 0)) return true;

    if (prev != 1) {
        ans[i] = 'B';
        if (f(i+1, a, b+1, prev, 1)) return true;
    }

    if (prev != 2 && pprev != 2) {
        ans[i] = 'C';
        if (f(i+1, a, b, prev, 2)) return true;
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    for (int i=0; i<(int) s.size(); i++) {
        cnt[s[i]-'A']++;
    }
    ans.resize(n);
    if (f(0, 0, 0, 3, 3)) cout << ans;
    else cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}