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
    vector<vector<ll>> v(n, vector<ll>(m)), tmp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    map<ll, ll> mp;
    vector<ll> cal(n);
    for (int i=0; i<n; i++) {
        ll ans = 0;
        for (int j=0; j<m; j++) {
            ans += v[i][j] * (j+1);
        }
        cal[i] = ans;
        mp[ans]++;
    }
    
    for (int i=0; i<n; i++) {
        if (mp[cal[i]] == 1) {
            cout << i+1 << ' ';
            int j = n-1;
            if (i == j) j = 0;
            cout << abs(cal[i] - cal[j]) << '\n';
        }
    }
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