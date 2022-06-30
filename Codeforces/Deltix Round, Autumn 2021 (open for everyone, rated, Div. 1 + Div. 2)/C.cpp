#include <bits/stdc++.h>
#define int long long
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

bool prime[1010101];

void solve() {
    int n, e; cin >> n >> e;
    vector<int> an(n);
    for (int i=0; i<n; i++) {
        cin >> an[i];
    }
    int ans = 0;
    for (int i=0; i<e; i++) {
        for (int z=i; z<n; z+=e) {
            if (prime[an[z]] == 0) {
                int left = 0, right = 0;
                for (int j=z-e; j>=0; j-=e) {
                    if (an[j] == 1) left++;
                    else break;
                }
                for (int j=z+e; j<n; j+=e) {
                    if (an[j] == 1) right++;
                    else break;
                }
                ans += left * (right+1) + right;
            }
        }
    }
    cout << ans << '\n';  
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<1010101; i++) {
        if (prime[i] == 0) {
            for (int j=i+i; j<1010101; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int T; cin >> T;
    while (T--) {
        solve();
    }
}