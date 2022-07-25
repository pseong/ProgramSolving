#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    set<int> st;
    int sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        sum += v[i];
        st.insert(v[i]);
    }
    int m; cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        auto it = st.lower_bound(x);
        if (it == st.end()) {
            it--;
        }
        int X = *it;
        int Y = sum - X;
        int gold = 0;
        if (X < x) gold = gold += x - X;
        if (Y < y) gold = gold += y - Y;

        int gold2 = 0;
        if (it != st.begin()) {
            it--;
            X = *it;
            Y = sum - X;
            if (X < x) gold2 = gold2 += x - X;
            if (Y < y) gold2 = gold2 += y - Y;
            gold = min(gold, gold2);
        }
        cout << gold << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}