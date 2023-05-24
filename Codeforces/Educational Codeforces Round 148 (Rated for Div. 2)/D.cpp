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
    
    int n, q;
    cin >> n >> q;
    vector<int> V(n);
    for (int i=0; i<n; i++) cin >> V[i];
    sort(all(V));
    while (q--) {
        int w;
        cin >> w;
        auto v = V;
        if (w <= n) {
            for (int i=0; i<w; i++) v[i] += w - i;
            int mn = *min_element(all(v));
            cout << mn << ' ';
        }
        else {
            int k = (w-n+1) / 2;
            if ((w-n)%2 == 0) for (int i=0; i<n; i++) v[i] += w - i;
            else for (int i=0; i<n-1; i++) v[i] += w - i;
            sort(all(v));
            ll sum = 0;
            for (int i=0; i<n; i++) sum += v[i] - v[0];
            if (sum >= k) cout << v[0] << ' ';
            else cout << v[0] - (k-sum+n-1)/n << ' ';
        }
    }
}