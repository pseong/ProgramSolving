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
 
vector<int> pos[3030];
int n, k;
vector<int> v;
 
bool calc(int m) {
    for (int i=0; i<=3000; i++) {
        int lo = i;
        int hi = lo+m-1;
        bool k = true;
        for (int j=0; j<n; j++) {
            bool ok = false;
            for (int x : pos[j]) {
                if (x >= lo && x <= hi) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                k = false;
                break;
            }
        }
        if (k) return true;
    }
    return false;
}
 
void solve() {
    for (int i=0; i<3030; i++) {
        pos[i].clear();
    }
    cin >> n >> k;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    srt(v);
    for (int i=0; i<n; i++) {
        for (int j=1; j<=k; j++) {
            pos[i].push_back(v[i] / j);
        }
        srt(pos[i]);
    }
 
    int lo = 1;
    int hi = 3000;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool cal = calc(mid);
        if (cal) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans-1 << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        solve();
    }
}