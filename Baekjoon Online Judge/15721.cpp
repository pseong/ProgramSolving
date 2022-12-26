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
    
    int a, t, s;
    cin >> a >> t >> s;
    int idx = 2;
    int ans = -1;
    int cnt = 0;
    while (true) {
        vector<int> v{0, 1, 0, 1};
        for (int i=0; i<idx; i++) v.push_back(0);
        for (int i=0; i<idx; i++) v.push_back(1);
        for (int i=0; i<(int)v.size(); i++) {
            ans++;
            if (v[i] == s) cnt++;
            if (cnt == t) {
                cout << ans % a << '\n';
                return 0;
            }
        }
        idx++;
    }
}