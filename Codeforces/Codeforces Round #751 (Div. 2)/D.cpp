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
    vector<int> an(n+1), bn(n+1);
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> bn[i];
    }
    
    vector<int> dchk(n+1);
    vector<int> uhist(n+1), dhist(n+1);
    queue<int> q;
    q.push(n);
    dchk[n] = 1;
    uhist[n] = n;
    dhist[n] = n;
    int ans = 0;
    int up = n;
    while (q.size()) {
        ans++;
        for (int i=0; i<q.size(); i++) {
            int x = q.front(); q.pop();
            if (x - an[x] <= 0) {
                uhist[0] = x;
                goto g;
            }
            for (int j=x-up; j<=an[x]; j++) {
                if (dchk[x-j+bn[x-j]]) continue;
                up = min(up, x-j);
                dchk[x-j+bn[x-j]] = 1;
                uhist[x-j] = x;
                dhist[x-j+bn[x-j]] = x-j;
                q.push(x-j+bn[x-j]);
            }
        }
    }
    cout << -1 << '\n';
    return;
    g:
    stack<int> st;
    st.push(0);
    int go = dhist[uhist[0]];
    while (go != n) {
        st.push(go);
        go = dhist[uhist[go]];
    }
    cout << st.size() << '\n';
    while (st.size()) {
        cout << st.top() << ' ';
        st.pop();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}