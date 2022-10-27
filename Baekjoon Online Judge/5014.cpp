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

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<int> chk(f+1);
    chk[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x - d >= 1 && chk[x - d] == 0) {
            chk[x - d] = chk[x] + 1;
            q.push(x - d);
        }
        if (x + u <= f && chk[x + u] == 0) {
            chk[x + u] = chk[x] + 1;
            q.push(x + u);
        }
    }
    if (chk[g]) cout << chk[g] - 1 << '\n';
    else cout <<  "use the stairs\n";
}       