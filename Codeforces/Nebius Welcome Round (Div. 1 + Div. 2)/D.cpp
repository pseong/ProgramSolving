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
    vector<string> v(n), v2(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    int lo = 0;
    int hi = 0;
    for (int i=0; i<n; i++) {
        int left = m / 4;
        for (int j=1; j<m; j++) {
            if (left && v2[i][j] == '1' && v2[i][j-1] == '1') {
                left--;
                v2[i][j] = '*';
                v2[i][j-1] = '*';
                lo++;
            }
        }
        for (int j=0; j<m; j++) {
            if (v2[i][j] == '1') lo++;
        }
 
        left = m / 4;
        for (int j=1; j<m; j++) {
            if (left && ((v[i][j] == '1' && v[i][j-1] == '0') || (v[i][j] == '0' && v[i][j-1] == '1'))) {
                left--;
                v[i][j] = '*';
                v[i][j-1] = '*';
                hi++;
            }
            else if (left && (v[i][j] == '0' && v[i][j-1] == '0')) {
                left--;
                v[i][j] = '*';
                v[i][j-1] = '*';
            }
        }
        for (int j=0; j<m; j++) {
            if (v[i][j] == '1') hi++;
        }
        hi -= left;
    }
    cout << lo << ' ' << hi << '\n';
}