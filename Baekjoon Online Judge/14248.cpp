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
    vector<int> v(n + 1), chk(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    int x;
    cin >> x;
    queue<int> q;
    q.push(x);
    chk[x] = 1;
    int ans = 0;
    while (q.size()) {
        ans++;
        int x = q.front();
        q.pop();
        for (int y : {x - v[x], x + v[x]}) {
            if (y < 1 || y > n) continue;
            if (chk[y]) continue;
            chk[y] = 1;
            q.push(y);
        }
    }
    cout << ans << '\n';
}