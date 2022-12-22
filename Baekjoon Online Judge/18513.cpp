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
    
    int n, k;
    cin >> n >> k;
    queue<int> q;
    map<int, int> dist;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        q.push(a);
        dist[a] = 0;
    }
    ll ans = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (dist.count(x-1) == 0) {
            k--;
            dist[x-1] = dist[x] + 1;
            ans += dist[x-1];
            q.push(x-1);
        }
        if (k == 0) break;
        if (dist.count(x+1) == 0) {
            k--;
            dist[x+1] = dist[x] + 1;
            ans += dist[x+1];
            q.push(x+1);
        }
        if (k == 0) break;
    }
    cout << ans << '\n';
}