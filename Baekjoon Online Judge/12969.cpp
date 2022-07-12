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

int n, k, dp[50][50][50][50];
string ans;
bool f(int i, int a, int b, int l) {
    if (i == n && k == l) return true;
    if (i >= n) return false;
    if (dp[i][a][b][l]) return false;
    dp[i][a][b][l] = 1;
    
    ans[i] = 'A';
    if (f(i+1, a+1, b, l)) return true;

    ans[i] = 'B';
    if (f(i+1, a, b+1, l+a)) return true;

    ans[i] = 'C';
    if (f(i+1, a, b, l+a+b)) return true;
    
    return false;
}

void solve() {
    cin >> n >> k;
    ans.resize(n);
    if (f(0, 0, 0, 0)) cout << ans;
    else cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}