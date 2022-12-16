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

vector<pi> v[101010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    for (int i=0; i<n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        v[y].push_back({x, t});
    }
    ll ans = 0;
    int nowx = 100000;
    ll noww = 0;
    multiset<pi> st;
    for (int i=0; i<=100000; i++) {
        for (auto [xx, tt] : v[i]) {
            if (xx <= nowx) {
                st.insert({xx, tt});
                noww += tt;
            }
        }
        while (st.size() > c) {
            nowx = (*st.rbegin()).first - 1;
            while (st.size() && (*st.rbegin()).first > nowx) {
                noww -= (*st.rbegin()).second;
                st.erase(prev(st.end()));
            }
        }
        ans = max(ans, noww);
    }
    cout << ans << '\n';
}