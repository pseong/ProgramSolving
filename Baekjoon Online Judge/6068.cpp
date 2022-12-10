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
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int now = v[0].first;
    int left = v[0].first - v[0].second;
    for (int i=1; i<n; i++) {
        if (now + v[i].second <= v[i].first) now += v[i].second;
        else {
            int gap = now + v[i].second - v[i].first;
            left -= gap;
            now = v[i].first;
        }
    }
    if (left < 0) {
        cout << -1 << '\n';
        return 0;
    }
    cout << left << '\n';
}