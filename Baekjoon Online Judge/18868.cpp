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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        map<int, int> mp;
        int idx = 1;
        vector<int> ve = v[i];
        sort(ve.begin(), ve.end());
        for (int i=0; i<m; i++) {
            if (mp[ve[i]] == 0) mp[ve[i]] = idx++;
        }
        for (int j=0; j<m; j++) {
            v[i][j] = mp[v[i][j]];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            bool ok = true;
            for (int k=0; k<m; k++) {
                if (v[i][k] != v[j][k]) ok = false;
            }
            if (ok) ans++;
        }
    }
    cout << ans << '\n';
}