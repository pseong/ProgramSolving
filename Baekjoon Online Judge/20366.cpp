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
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<ti> v2;
    sort(v.begin(), v.end());
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            v2.push_back({v[i] + v[j], i, j});
        }
    }
    int ans = 1e9;
    for (int i=0; i<(int)v2.size(); i++) {
        auto [x, a, b] = v2[i];
        int l = 0;
        int r = n - 1;
        while (true) {
            while (l == a || l == b) l++;
            while (r == a || r == b) r--;
            if (l >= r) break;
            int y = v[l] + v[r];
            ans = min(ans, abs(x - y));
            if (x <= y) r--;
            else l++;
        }
    }
    cout << ans << '\n';
}