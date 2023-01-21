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

vector<int> primes;
int prime[101010];

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (m == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> lst;
    for (int p=2; p<=m; p++) {
        lst.push_back({});
        for (int i=0; i<n; i++) {
            if (v[i] % p == 0) lst.back().push_back(v[i]);
        }
    }
    multiset<ti> ms;
    for (int i=0; i<(int)lst.size(); i++) {
        if (lst[i].empty()) {
            cout << -1 << '\n';
            return;
        }
        ms.insert({lst[i][0], i, 0});
    }
    int ans = get<0>(*ms.rbegin()) - get<0>(*ms.begin());
    while (true) {
        auto [x, i, j] = *ms.begin();
        ms.erase(ms.begin());
        if (lst[i].size() == j+1) break;
        ms.insert({lst[i][j+1], i, j+1});
        ans = min(ans, (get<0>(*ms.rbegin()) - get<0>(*ms.begin())));
    }
    cout << ans << '\n';
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