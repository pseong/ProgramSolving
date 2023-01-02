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

int n, x, y, z, ans, v[30];

void go(int idx) {
    if (idx == z) {
        go(idx + 1);
        return;
    }
    if (idx == n + 1) {
        ans++;
        return;
    }
    for (int i=idx+1; i<n*2; i++) {
        if (v[i] == 0 && v[i-idx-1] == 0) {
            v[i] = idx;
            v[i-idx-1] = idx;
            go(idx + 1);
            v[i] = 0;
            v[i-idx-1] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> x >> y;
    z = y - x - 1;
    v[x-1] = z;
    v[y-1] = z;
    go(1);
    cout << ans << '\n';
}