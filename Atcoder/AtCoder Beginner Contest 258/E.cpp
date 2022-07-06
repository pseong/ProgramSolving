#include <bits/stdc++.h>
#define int long long
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

int pref[404040];
int w[404040];
int adj[404040];
int cnt[404040];
int chk[404040];
int hist[404040];

void solve() {
    int n, q, x;
    cin >> n >> q >> x;
    for (int i=0; i<n; i++) {
        cin >> w[i];
        w[i+n] = w[i];
    }
    pref[0] = w[0];
    for (int i=1; i<2*n; i++) {
        pref[i] = pref[i-1] + w[i];
    }
    for (int i=0; i<n; i++) {
        int to = x;
        int sum = pref[i+n-1] - pref[i-1];
        cnt[i] = to/sum * n;
        to %= sum;
        if (to > 0) {
            if (i != 0) to += pref[i-1];
            auto it = lower_bound(pref+i, pref+i+n, to);
            adj[i] = i + it - (pref + i) + 1;
            cnt[i] += adj[i] - i;
            adj[i] %= n;
        }
        else {
            adj[i] = i;
        }
    }
    int go = 0;
    vector<int> v, v2;
    while (true) {
        chk[go] = 1;
        v.push_back(cnt[go]);
        hist[go] = (int) v.size()-1;
        go = adj[go];
        if (chk[go]) {
            int start = hist[go];
            for (int i=start; i<(int) v.size(); i++) {
                v2.push_back(v[i]);
            }
            v.erase(v.begin() + start, v.end());
            break;
        }
    }
    for (int Q=0; Q<q; Q++) {
        int k; cin >> k;
        k--;
        if (k < (int) v.size()) {
            cout << v[k] << '\n';
            continue;
        }
        k -= (int) v.size();
        k %= (int) v2.size();
        cout << v2[k] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}