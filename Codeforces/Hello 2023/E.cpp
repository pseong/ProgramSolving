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
        string out(n, '1');
        out[i] = '0';
        cout << "? " << i + 1 << " " << out << endl;
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    string ans(n, '0');
    ans[v[0].second] = '1';
    int w = v[0].first;
    for (int i=1; i<n; i++) {
        auto [cnt, x] = v[i];
        string out(n, '0');
        for (int i=0; i<n; i++) {
            if (ans[i] == '1') out[i] = '1';
        }
        cout << "? " << x + 1 << ' ' << out << endl;
        int res;
        cin >> res;
        if (res) {
            for (int j=0; j<=i; j++) ans[v[j].second] = '1';
        }
    }
    cout << "! " << ans << endl;
}