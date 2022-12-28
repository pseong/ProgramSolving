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
    vector<int> chk(m + 1);
    vector<vector<int>> v(n + 1);
    for (int i=1; i<=n; i++) {
        int c;
        cin >> c;
        v[i].resize(c);
        for (int j=0; j<c; j++) {
            cin >> v[i][j];
            chk[v[i][j]]++;
        }
    }
    for (int i=1; i<=n; i++) {
        bool ok = true;
        for (int j=0; j<(int)v[i].size(); j++) {
            if (chk[v[i][j]] == 1) ok = false;
        }
        if (ok) {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}