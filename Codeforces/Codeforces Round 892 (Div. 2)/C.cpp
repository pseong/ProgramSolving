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
    int ans = 0;
    for (int m=1; m<=n*n; m++) {
        vector<int> v(n + 1);
        set<int> st;
        for (int i=1; i<=n; i++) st.insert(i);
        for (int i=n; i>=1; i--) {
            auto it = st.upper_bound(m/i);
            if (it == st.begin()) break;
            it--;
            v[i] = *it;
            st.erase(it);
        }
        int mx = 0, res = 0;
        for (int i=1; i<=n; i++) {
            res += i * v[i];
        }
        ans = max(ans, res - m);
    }
    cout << ans << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}