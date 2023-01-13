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

int chk[202020], c[202020];

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v, lst(n);
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        lst[i] = k;
        for (int j=0; j<k; j++) {
            int a;
            cin >> a;
            v.push_back(a);
            if (c[a] != CASE) chk[a] = 0;
            c[a] = CASE;
            chk[a]++;
        }
    }
    int now = 0;
    for (int i=0; i<n; i++) {
        bool ok = true;
        for (int j=0; j<(int)lst[i]; j++) {
            if (chk[v[now]] == 1) ok = false;
            now++;
        }
        if (ok) {
            yes();
            return;
        }
    }
    no();
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