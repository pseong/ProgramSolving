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

    int n, k;
    cin >> n >> k;
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int ridx = 0;
    int lidx = 0;
    sort(v.begin(), v.end());
    int r = -1;
    int now = 0;
    multiset<int> lms, rms;
    for (int l=0; l<=1000000; l++) {
        while (lidx < n && l == v[lidx].first) {
            lms.insert(v[lidx].second);
            lidx++;
        }
        while (r + 1 <= 1000000 && now < k) {
            while (rms.size() && *rms.begin() == r) {
                rms.erase(rms.begin());
            }
            r++;
            now += rms.size();
            while (ridx < n && r == v[ridx].first) {
                rms.insert(v[ridx].second);
                ridx++;
            }
        }
        if (now == k) {
            cout << l << ' ' << r << '\n';
            return 0;
        }
        while (lms.size() && *lms.begin() == l) {
            lms.erase(lms.begin());
        }
        now -= lms.size();
    }
    cout << 0 << ' ' << 0 << '\n';
}