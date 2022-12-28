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
    vector<int> v(n), w(n);
    for (int i=0; i<n; i++) cin >> v[i];
    for (int i=0; i<n; i++) cin >> w[i];
    vector<pi> lst;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            lst.push_back({v[i] * w[j], j});
        }
    }
    sort(lst.rbegin(), lst.rend());
    vector<int> dis(n);
    for (int i=0; i<(int)lst.size(); i++) {
        if (k && !dis[lst[i].second]) {
            dis[lst[i].second] = 1;
            k--;
        }
        if (dis[lst[i].second]) continue;
        cout << lst[i].first << '\n';
        return 0;
    }
}