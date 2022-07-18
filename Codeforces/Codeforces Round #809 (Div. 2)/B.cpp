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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+1, vector<int>());
    vector<int> an(n+1);
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        v[an[i]].push_back(i);
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        vector<int>& vec = v[i];
        int sz = vec.size();
        vector<int> cnt(2);
        int ans = 0;
        for (int j=0; j<sz; j++) {
            if (vec[j]%2 == 0) cnt[0] = max(cnt[0], cnt[1] + 1);
            else cnt[1] = max(cnt[1], cnt[0] + 1);
        }
        cout << max(cnt[0], cnt[1]) << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}