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
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    int curp = 1;
    int curq = 1;
    vector<int> p(n + 1), q(n + 1);
    vector<int> chkp(n + 1), chkq(n + 1);
    for (int k=0; k<n; k++) {
        auto [x, i] = v[k];
        while (chkq[curq]) curq++;
        while (chkp[curp]) curp++;
        if (chkp[x] == 0 && curq <= x) {
            chkp[x] = 1;
            p[i] = x;
            chkq[curq] = 1;
            q[i] = curq;
        }
        else if (chkq[x] == 0 && curp <= x) {
            chkq[x] = 1;
            q[i] = x;
            chkp[curp] = 1;
            p[i] = curp;
        }
        else {
            no();
            return;
        }
    }
    yes();
    for (int i=1; i<=n; i++) cout << p[i] << " \n"[i == n];
    for (int i=1; i<=n; i++) cout << q[i] << " \n"[i == n];
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