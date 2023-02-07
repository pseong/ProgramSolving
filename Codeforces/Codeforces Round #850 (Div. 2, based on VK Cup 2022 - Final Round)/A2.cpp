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
    n--;
    vector<vector<int>> v(2, vector<int>(2));
    v[0][0] = 1;
    int idx = 1;
    ll now = 2;
    ll sum = 1;
    while (true) {
        for (int i=0; i<2; i++) {
            if (n < now) {
                v[idx][0] += n/2;
                v[idx][1] += n/2;
                if (n%2) {
                    if (sum%2) v[idx][1]++;
                    else v[idx][0]++;
                }
                goto g;
            }
            v[idx][0] += now/2;
            v[idx][1] += now/2;
            if (now%2) {
                if (sum%2) v[idx][1]++;
                else v[idx][0]++;
            }
            n -= now;
            sum += now;
            now++;
        }
        idx ^= 1;
    }
    g:
    cout << v[0][0] << ' ' << v[0][1] << ' ' << v[1][0] << ' ' << v[1][1] << '\n';
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