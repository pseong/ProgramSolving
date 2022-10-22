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
    ll ans = 0;
    stack<pi> st;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (st.size() && st.top().first > a) {
            ans += 1;
            st.push({a, 1});
        }
        else if (st.size() && st.top().first == a) {
            ans += st.top().second;
            if (st.size() > 1) ans += 1;
            st.top().second++;
        }
        else {
            while (st.size() && st.top().first < a) {
                ans += st.top().second;
                st.pop();
            }
            if (st.size() && st.top().first == a) {
                ans += st.top().second;
                if (st.size() > 1) ans += 1;
                st.top().second++;
            }
            else  {
                if (st.size() && st.top().first > a) ans += 1;
                st.push({a, 1});
            }
        }
    }
    cout << ans << '\n';
}