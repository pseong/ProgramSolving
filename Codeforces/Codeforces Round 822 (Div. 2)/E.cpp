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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        cin >> v[i][i];
    }
    for (int i=0; i<n-1; i++) {
        int prev = v[i][i];
        for (int j=i+1; j<i+n; j++) {
            v[i][j%n] = (prev+i+1) % n;
            prev = v[i][j%n];
        }
    }
    for (int j=0; j<n; j++) {
        v[n-1][j] = v[n-1][n-1];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}