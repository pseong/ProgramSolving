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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int mx = 0;
    vector<int> chk(n);
    for (int i=0; i<n; i++) {
        mx = max(mx, v[i]);
        if (mx > v[i]) {
            chk[i] = 1;
        }
    }
    vector<int> right(n);
    stack<int> st;
    for (int i=0; i<n; i++) {
        while (st.size() && v[st.top()] < v[i]) {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        right[st.top()] = n;
        st.pop();
    }
    for (int i=0; i<q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        if (v[x] == n) {
            cout << max(0, k - max(0, x - 1)) << '\n';
        }
        else if (chk[x] == 1) {
            cout << 0 << '\n';
        }
        else {
            if (k < x) {
                cout << 0 << '\n';
            }
            else {
                cout << (x == 0 ? 0 : 1) + min(k - x, right[x] - x - 1) << '\n';
            }
        }
    }
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