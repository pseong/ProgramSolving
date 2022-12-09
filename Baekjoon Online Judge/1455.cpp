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

string s[110];

void go(int x, int y) {
    for (int i=0; i<=x; i++) {
        for (int j=0; j<=y; j++) {
            s[i][j] ^= '0'^'1';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            if (s[i][j] == '1') {
                ans++;
                go(i, j);
            }
        }
    }
    cout << ans << '\n';
}