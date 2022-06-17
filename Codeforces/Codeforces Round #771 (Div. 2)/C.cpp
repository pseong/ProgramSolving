#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    set<int> st;
    int now = 0, ans = 0;
    for (int i=0; i<n; i++) {
        if (now < v[i]) {
            for (int j=now+1; j<=v[i]; j++) {
                st.insert(j);
            }
            now = v[i];
        }
        st.erase(v[i]);
        if (st.empty()) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}