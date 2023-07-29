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
    vector<int> v(n + 2), chk(n + 2);
    chk[0] = 1;
    for (int i=1; i<=n; i++) cin >> v[i];
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            ans++;
            int j = i;
            bool k = 0;
            while (j<=n && v[j]) {
                chk[j] = 1;
                if (v[j] == 2) k = 1;
                j++;
            }
            if (k) {
                chk[i-1] = 1;
                chk[j] = 1;
            }
            else {
                if (chk[i-1]) chk[j] = 1;
                else chk[i-1] = 1;
            }
            i = j;
        }
    }
    for (int i=1; i<=n; i++) if (!chk[i]) ans++;
    cout << ans << '\n';
}