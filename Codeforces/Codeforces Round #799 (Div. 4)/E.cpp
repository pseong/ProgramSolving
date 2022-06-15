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
        int sum = 0;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if (sum < k) {
            cout << -1 << '\n';
            continue;
        }
        int cnt = 0;
        int ans = n;
        for (int l=0, r=-1; l<n; l++) {
            while (r < n-1 && cnt+v[r+1] <= k) {
                r++;
                cnt += v[r];
            }
            if (cnt == k) {
                ans = min(ans, n - (r - l + 1));
            }
            cnt -= v[l];
        }
        cout << ans << '\n';
    }
}