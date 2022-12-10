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
    int m;
    cin >> m;
    int mn = n - 1 - (min_element(v.rbegin(), v.rend()) - v.rbegin());
    int mn2 = n - 1 - (min_element(v.rbegin(), prev(v.rend())) - v.rbegin());
    vector<int> w;
    if (m - v[mn2] < 0) {
        cout << 0 << '\n';
        return 0;
    }
    w.push_back(mn2);
    m -= v[mn2];
    int cnt = m / v[mn];
    for (int i=0; i<cnt; i++) {
        w.push_back(mn);
    }
    m -= cnt * v[mn];
    sort(w.rbegin(), w.rend());
    for (int i=0; i<(int)w.size(); i++) {
        for (int j=n-1; j>w[i]; j--) {
            if (m + v[w[i]] - v[j] >= 0) {
                m += v[w[i]] - v[j];
                w[i] = j;
            }
        }
    }
    for (int i=0; i<(int)w.size(); i++) {
        cout << w[i];
    }
    cout << '\n';
}