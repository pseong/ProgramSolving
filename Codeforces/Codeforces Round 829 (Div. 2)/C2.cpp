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
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += v[i];
    }
    if (abs(sum)%2) {
        cout << -1 << '\n';
        return;
    }
    if (sum == 0) {
        cout << n << '\n';
        for (int i=1; i<=n; i++) {
            cout << i << ' ' << i << '\n';
        }
        return;
    }
    if (sum < 0) {
        sum = -sum;
        for (int i=1; i<=n; i++) v[i] = -v[i];
    }
    vector<pi> ans;
    for (int i=2; i<=n; i++) {
        if (sum > 0 && v[i] == 1) {
            sum -= 2;
            ans.push_back({i - 1, i});
            i++;
        }
        else ans.push_back({i - 1, i - 1});
    }
    if (ans.empty() || ans.back().second != n) ans.push_back({n, n});
    if (sum != 0) {
        cout << -1 << '\n';
        return;
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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