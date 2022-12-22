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
    
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    vector<int> chk(100001, -1);
    queue<int> q;
    q.push(n);
    chk[n] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : {x - 1, x + 1, x - a, x + a, x - b, x + b, x * a, x * b}) {
            if (y < 0 || y > 100000) continue;
            if (chk[y] != -1) continue;
            chk[y] = chk[x] + 1;
            q.push(y);
        }
    }
    cout << chk[m] << '\n';
}