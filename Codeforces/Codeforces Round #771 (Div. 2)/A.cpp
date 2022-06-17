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
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        if (v[i] != i) {
            for (int j=i+1; j<=n; j++) {
                if (v[j] == i) {
                    reverse(v.begin()+i, v.begin()+j+1);
                    goto g;
                }
            }
        }
    }
    g:
    for (int i=1; i<=n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}