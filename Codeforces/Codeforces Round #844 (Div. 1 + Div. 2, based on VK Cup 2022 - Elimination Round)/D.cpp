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
    int ans = 1;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int d = v[j] - v[i];
            for (int x=1; x*x<=d; x++) {
                if (d%x == 0) {
                    int y = d/x;
                    if ((x + y) % 2 != 0) continue;
                    ll a = (x + y) / 2;
                    ll df = a*a - v[j];
                    if (df < 0) continue;
                    int res = 0;
                    for (int i=0; i<n; i++) {
                        if ((ll)sqrt(v[i] + df) * (ll)sqrt(v[i] + df) == v[i] + df) res++;
                    }
                    if (ans < res) ans = res;
                }
            }
        }
    }
    cout << ans << '\n';
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