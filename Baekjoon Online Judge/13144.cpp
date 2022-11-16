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
    vector<int> v(n), cnt(101010);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int l = 0;
    int r = -1;
    ll ans = 0;
    while (r < n - 1) {
        r++;
        cnt[v[r]]++;
        if (r == n || cnt[v[r]] == 2) {
            ans += (ll)(r - l) * (r - l + 1) / 2;
            while (l < n && cnt[v[l]] != 2) {
                cnt[v[l]]--;
                l++;
            }
            if (l < n) cnt[v[l]]--;
            l++;
            ans -= (ll)(r - l) * (r - l + 1) / 2;
        }
    }
    ans += (ll)(r - l + 1) * (r - l + 2) / 2;
    cout << ans << '\n';
}