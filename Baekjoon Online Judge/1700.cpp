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

    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    vector<int> nxt(k), cal(k + 1, 1000000);
    for (int i=0; i<k; i++) {
        cin >> v[i];
    }
    for (int i=k-1; i>=0; i--) {
        nxt[i] = cal[v[i]];
        cal[v[i]] = i;
    }
    vector<int> chk(k + 1);
    vector<pi> q;
    int ans = 0;
    for (int i=0; i<k; i++) {
        if (chk[v[i]]) {
            for (int z=0; z<(int)q.size(); z++) {
                if (q[z].first == v[i]) {
                    q[z].second = nxt[i];
                }
            }
            continue;
        }
        if (q.size() == n) {
            ans++;
            vector<int> aa(2, -1);
            for (int z=0; z<(int)q.size(); z++) {
                if (aa[1] < q[z].second) {
                    aa[0] = z;
                    aa[1] = q[z].second;
                }
            }
            chk[q[aa[0]].first] = 0;
            q.erase(q.begin() + aa[0]);
        }
        chk[v[i]] = 1;
        q.push_back({v[i], nxt[i]});
    }
    cout << ans << '\n';
}