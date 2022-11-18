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

    int n, q;
    cin >> n >> q;
    set<int> st;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (a == 1) st.insert(i);
    }
    int now = 1;
    for (int i=0; i<q; i++) {
        int wh;
        cin >> wh;
        if (wh == 1) {
            int a;
            cin >> a;
            if (st.find(a) == st.end()) st.insert(a);
            else st.erase(a);
        }
        else if (wh == 2) {
            int x;
            cin >> x;
            now = (now + x - 1) % n + 1;
        }
        else if (wh == 3) {
            if (st.empty()) cout << -1 << '\n';
            else {
                auto it = st.lower_bound(now);
                if (it != st.end()) cout << *it - now << '\n';
                else {
                    it = st.lower_bound(1);
                    cout << n - now + *it << '\n';
                }
            }
        }
    }
}