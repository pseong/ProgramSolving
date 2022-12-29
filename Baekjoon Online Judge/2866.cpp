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

string v[1010];
int n, m;

bool cal(int x) {
    set<string> st;
    for (int j=0; j<m; j++) {
        string s;
        for (int i=x; i<n; i++) {
            s.push_back(v[i][j]);
        }
        if (st.count(s)) return false;
        st.insert(s);
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int lo = 0;
    int hi = n - 1;
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cal(m)) {
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    cout << ans << '\n';
}