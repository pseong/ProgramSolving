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
    string a, b;
    cin >> n >> a >> b;
    string ra = a;
    for (int i=0; i<n; i++) ra[i] ^= '0' ^ '1';
    if (b != a && b != ra) {
        no();
        return;
    }
    vector<pi> ans;
    int s = 0;
    int cnt = 0;
    if (a != b) {
        ans.push_back({1, n});
        a = ra;
    }
    for (int i=0; i<=n; i++) {
        if (i == n && a[i-1] == '1' || i>0 && a[i] == '0' && a[i-1] == '1') {
            ans.push_back({s+1, i});
            cnt++;
        }
        else if (i>0 && i<n && a[i] == '1' && a[i-1] == '0') s = i;
    }
    if (cnt%2) {
        ans.push_back({1, n});
        ans.push_back({1, 1});
        ans.push_back({2, n});
    }
    yes();
    cout << ans.size() << '\n';
    for (auto [s, e] : ans) {
        cout << s << ' ' << e << '\n';
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