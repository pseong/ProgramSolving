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
    vector<ll> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<int> lu(n + 1), ld(n + 1), ru(n + 1), rd(n + 1);
    stack<int> st;
    for (int i=1; i<=n; i++) {
        while (st.size() && v[st.top()] < v[i]) st.pop();
        if (st.size()) lu[i] = st.top();
        st.push(i);
    }
    while (st.size()) st.pop();
    for (int i=1; i<=n; i++) {
        while (st.size() && v[st.top()] > v[i]) st.pop();
        if (st.size()) ld[i] = st.top();
        st.push(i);
    }
    while (st.size()) st.pop();
    for (int i=1; i<=n; i++) {
        while (st.size() && v[st.top()] < v[i]) {
            ru[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        ru[st.top()] = n + 1;
        st.pop();
    }
    for (int i=1; i<=n; i++) {
        while (st.size() && v[st.top()] > v[i]) {
            rd[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        rd[st.top()] = n + 1;
        st.pop();
    }
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += v[i] * (i - lu[i]) * (ru[i] - i);
        ans -= v[i] * (i - ld[i]) * (rd[i] - i);
    }
    cout << ans << '\n';
}