#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vi v(n);
        deque<int> idx;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            if (v[i] == 1) idx.push_back(i);
        }
        if (idx.size() < k) {
            cout << -1 << '\n';
            continue;
        }
        int l = 0;
        int r = k-1;
        int ans = 0;
        if (r+1 < idx.size()) ans += n-idx[r+1];
        if (l-1 >= 0) ans += idx[l-1]+1;
        while (r < idx.size()) {
            int res = 0;
            l++;
            r++;
            if (r+1 < idx.size()) res += n-idx[r+1];
            if (l-1 >= 0) res += idx[l-1]+1;
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}