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

    int T; cin >> T;
    for (int TT=1; TT<=T; TT++) {
        int w, h;
        cin >> w >> h;
        vector<ll> vec;
        ll ans = 0;
        for (int i=0; i<2; i++) {
            vec.clear();
            int k;
            cin >> k;
            while (k--) {
                int a;
                cin >> a;
                vec.push_back(a);
            }
            ans = max(ans, (vec.back() - vec.front()) * h);
        }
        for (int i=0; i<2; i++) {
            vec.clear();
            int k;
            cin >> k;
            while (k--) {
                int a;
                cin >> a;
                vec.push_back(a);
            }
            ans = max(ans, (vec.back() - vec.front()) * w);
        }
        cout << ans << '\n';
        g:
        continue;
    }
}