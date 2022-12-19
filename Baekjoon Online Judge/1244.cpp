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

int v[110];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            for (int i=b; i<=n; i+=b) {
                v[i] ^= 1;
            }
        }
        else if (a == 2) {
            int l = b;
            int r = b;
            while (l > 1 && r < n && v[l-1] == v[r+1]) l--, r++;
            for (int i=l; i<=r; i++) {
                v[i] ^= 1;
            }
        }
    }
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cout << v[i] << ' ';
        cnt++;
        if (cnt % 20 == 0) cout << '\n';
    }
}