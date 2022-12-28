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

int n;

vector<int> f(int x, vector<int>& v) {
    int N = (1 << x);
    vector<int> tmp(N);
    int now = 0;
    for (int i=0; i<=x; i++) {
        int nxt = (1<<i);
        int cnt = nxt - now;
        int g = N - nxt;
        for (int j=now; j<nxt; j++) {
            tmp[g] = v[j];
            g++;
        }
        now = nxt;
    }
    vector<int> res;
    for (int i=now; i<n; i++) {
        res.push_back(v[i]);
    }
    res.insert(res.end(), tmp.begin(), tmp.end());
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    vector<int> now(n);
    for (int i=0; i<n; i++) now[i] = n - i; 
    for (int x=0; x<10; x++) {
        for (int y=0; y<10; y++) {
            if (n < 1<<x || n < 1<<y) continue;
            vector<int> tmp = f(x, now);
            vector<int> res = f(y, tmp);
            reverse(res.begin(), res.end());
            bool ok = true;
            for (int i=0; i<n; i++) {
                if (v[i] != res[i]) ok = false;
            }
            if (ok) {
                cout << x << ' ' << y << '\n';
                return 0;
            }
        }
    }
}