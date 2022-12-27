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

vector<vector<int>> now;

bool chk(int x, int y, vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+m; j++) {
            if (i >= (int)now.size() || j >= (int)now[0].size() || now[i][j] && v[i-x][j-y]) return false;
        }
    }
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+m; j++) {
            now[i][j] |= v[i-x][j-y];
        }
    }
    return true;
}

vector<vector<int>> rotate(vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ret[j][n-1-i] = v[i][j];
        }
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> v(k, vector<vector<int>>());
    for (int i=0; i<k; i++) {
        int n, m;
        cin >> n >> m;
        v[i].resize(n, vector<int>(m));
        for (int a=0; a<n; a++) {
            for (int b=0; b<m; b++) {
                cin >> v[i][a][b];
            }
        }
    }
    now.resize(n, vector<int>(m));
    for (int q=0; q<k; q++) {
        for (int t=0; t<4; t++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (chk(i, j, v[q])) goto g;
                }
            }
            v[q] = rotate(v[q]);
        }
        g:
        continue;
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (now[i][j]) ans++;
        }
    }
    cout << ans << '\n';
}