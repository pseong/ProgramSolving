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

int n, m, ans, v[10], chk[10];

void go(int idx) {
    if (idx == n) {
        bool ok = true;
        for (int i=0; i<m; i++) {
            if (chk[v[i]] == 0) ok = false;
        }
        if (ok) ans++;
        return;
    }
    for (int i=0; i<10; i++) {
        chk[i]++;
        go(idx + 1);
        chk[i]--;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> v[i];
    }
    go(0);
    cout << ans << '\n';
}