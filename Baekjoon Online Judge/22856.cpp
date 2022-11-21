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

struct Node {
    int l, r;
} v[101010];

int ans;
void go(int x) {
    if (v[x].l != -1) {
        ans += 2;
        go(v[x].l);
    }
    if (v[x].r != -1) {
        ans += 2;
        go(v[x].r);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].l = b;
        v[a].r = c;
    }
    go(1);
    int g = 1;
    int cnt = 0;
    while (v[g].r != -1) {
        cnt++;
        g = v[g].r;
    }
    cout << ans - cnt << '\n';
}