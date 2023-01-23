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
    set<int> st;
    for (int i=1; i<=n; i++) st.insert(i);
    while (st.size() >= 3) {
        int a = *st.begin();
        st.erase(st.begin());
        int b = *st.begin();
        st.erase(st.begin());
        int c = *st.begin();
        st.erase(st.begin());
        cout << "? " << a << ' ' << b << endl;
        int ab;
        cin >> ab;
        cout << "? " << b << ' ' << c << endl;
        int bc;
        cin >> bc;
        if (ab == bc) st.insert(a), st.insert(c);
        else if (ab > bc) st.insert(a), st.insert(b);
        else st.insert(b), st.insert(c);
    }
    cout << "! " << *st.begin() << ' ' << *st.rbegin() << endl;
    int r;
    cin >> r;
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