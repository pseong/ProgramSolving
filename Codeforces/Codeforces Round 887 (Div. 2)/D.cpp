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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    srt(v);
    deque<pi> q(v.begin(), v.end());
    vector<int> ans(n);
    int m = 0;
    int now = n;
    while (q.size()) {
        if (q.front().first - m == 0 && q.back().first - m == now) {
            no();
            return;
        }
        else if (q.front().first - m == 0) {
            auto [x, y] = q.front();
            q.pop_front();
            ans[y] = -now;
            now--;
        }
        else if (q.back().first - m == now) {
            auto [x, y] = q.back();
            q.pop_back();
            ans[y] = now;
            now--;
            m++;
        }
        else {
            no();
            return;
        }
    }
    yes();
    for (int x : ans) cout << x << ' ';
    cout << '\n';
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