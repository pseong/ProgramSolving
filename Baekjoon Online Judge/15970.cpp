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
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n, 1e9);
    vector<int> left(100001, -1e9), right(100001, 1e9);
    for (int i=0; i<(int)v.size(); i++) {
        ans[i] = min(ans[i], v[i].first - left[v[i].second]);
        left[v[i].second] = v[i].first;
    }
    for (int i=(int)v.size()-1; i>=0; i--) {
        ans[i] = min(ans[i], right[v[i].second] - v[i].first);
        right[v[i].second] = v[i].first;
    }
    cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
}