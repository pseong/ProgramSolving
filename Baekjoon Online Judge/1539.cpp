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

struct S {
    ll l, r, h;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<S> v(n);
    for (int i=0; i<n; i++) {
        v[i].l = -1;
        v[i].r = -1;
    }
    int a;
    cin >> a;
    set<int> st{a};
    v[a].h = 1;
    for (int i=1; i<n; i++) {
        cin >> a;
        st.insert(a);
        auto it = st.find(a);
        int pre = -1;
        int nxt = -1;
        if (it != st.begin()) pre = *(prev(it));
        if (next(it) != st.end()) nxt = *(next(it));
        if (pre == -1 || v[pre].r != -1) {
            v[nxt].l = a;
            v[a].h = v[nxt].h + 1;
        }
        else {
            v[pre].r = a;
            v[a].h = v[pre].h + 1;
        }
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += v[i].h;
    }
    cout << ans << '\n';
}