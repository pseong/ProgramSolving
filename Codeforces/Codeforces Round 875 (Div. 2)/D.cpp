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

int mp[650][200020];

void solve(int CASE) {
    int n;
    cin >> n;
    int sqrt2N = sqrt(n*2) + 5;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=sqrt2N; j++) {
            mp[j][i] = 0;
        }
    }
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    ll ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] <= sqrt2N) {
            for (int j=1; j<=sqrt2N; j++) {
                if (a[i]*j - b[i] < 0) continue;
                if (a[i]*j - b[i] > n) break;
                ans += mp[j][a[i]*j - b[i]];
            }
            mp[a[i]][b[i]]++;
        }
    }
    for (int i=0; i<n; i++) {
        if (a[i] > sqrt2N) {
            for (int j=1; j<=sqrt2N; j++) {
                if (a[i]*j - b[i] < 0) continue;
                if (a[i]*j - b[i] > n) break;
                ans += mp[j][a[i]*j - b[i]];
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