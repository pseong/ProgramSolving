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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
            sum += v[i][j];
        }
    }
    if (sum % n) {
        cout << -1 << '\n';
        return;
    }
    int x = sum / n;
    int ans1 = 0;
    vector<int> need(n);
    for (int i=0; i<n; i++) {
        int res = 0;
        for (int j=0; j<m; j++) {
            res += v[i][j];
        }
        if (res < x) ans1 += x - res;
        need[i] = x - res;
    }
    vector<ti> ans2;
    for (int j=0; j<m; j++) {
        vector<int> plus, minus;
        for (int i=0; i<n; i++) {
            if (need[i] > 0 && v[i][j] == 0) plus.push_back(i);
            else if (need[i] < 0 && v[i][j] == 1) minus.push_back(i);
        }
        for (int i=0; i<(int)min(plus.size(), minus.size()); i++) {
            ans2.push_back({minus[i], plus[i], j});
            need[minus[i]]++;
            need[plus[i]]--;
        }
    }
    cout << ans1 << '\n';
    for (auto [x, y, z] : ans2) {
        cout << x+1 << ' ' << y+1 << ' ' << z+1 << '\n';
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