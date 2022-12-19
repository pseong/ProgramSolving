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

string s[3030];
int d[3030], u[3030];
vector<string> ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    ans.assign(n, string(m, '.'));

    for (int j=0; j<m; j++) {
        d[j] = n;
        for (int i=n-1; i>=0; i--) {
            if (s[i][j] == '#') d[j] = i;
        }
    }
    for (int j=0; j<m; j++) {
        u[j] = -1e9;
        for (int i=0; i<n; i++) {
            if (s[i][j] == 'X') {
                u[j] = i;
            }
        }
    }

    int mn = n;
    for (int i=0; i<m; i++) {
        mn = min(mn, d[i] - u[i]);
    }
    mn--;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            if (s[i][j] == '#') ans[i][j] = '#';
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            if (s[i][j] == 'X') {
                ans[i+mn][j] = 'X';
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout << ans[i] << '\n';
    }
}