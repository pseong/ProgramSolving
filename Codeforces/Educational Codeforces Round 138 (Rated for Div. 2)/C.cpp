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

bool game(vector<int> v, int k) {
    multiset<int> ms(v.begin(), v.end());
    for (int i=1; i<=k; i++) {
        if (ms.empty()) return false;
        auto it = ms.upper_bound(k-i+1);
        it--;
        if (*it > k-i+1) return false;
        ms.erase(it);
        if (ms.size()) ms.erase(ms.begin());
    }
    return true;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    int lo = 1, hi = n;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (game(v, mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    if (ans == -1) cout << 0 << '\n';
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}