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
    
    int h, w;
    cin >> h >> w;
    vector<int> v(w + 2);
    for (int i=1; i<=w; i++) {
        cin >> v[i];
    }
    vector<int> mxl(w + 2), mxr(w + 2);
    for (int i=1; i<=w; i++) {
        mxl[i] = max(mxl[i-1], v[i]);
    }
    for (int i=w; i>=1; i--) {
        mxr[i] = max(mxr[i+1], v[i]);
    }
    int ans = 0;
    for (int i=1; i<=w; i++) {
        ans += max(0, min(mxl[i-1], mxr[i+1]) - v[i]);
    }
    cout << ans << '\n';
}