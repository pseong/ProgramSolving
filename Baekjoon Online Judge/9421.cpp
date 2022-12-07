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

int prime[1010101];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (prime[i] == 0) {
            for (int j=i+i; j<=n; j+=i) {
                prime[j] = 1;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (prime[i] == 1) continue;
        map<int, bool> chk;
        int go = i;
        chk[go] = 1;
        while (true) {
            int g = go;
            int nxt = 0;
            while (g) {
                nxt += (g % 10) * (g % 10);
                g /= 10;
            }
            if (nxt == 1) {
                cout << i << '\n';
                break;
            }
            else if (!chk[nxt]) chk[nxt] = 1;
            else break;
            go = nxt;
        }
    }
}