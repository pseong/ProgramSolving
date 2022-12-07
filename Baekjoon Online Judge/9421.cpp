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

int chk[1010101], prime[1010101], sgs[1010101];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<1010101; i++) {
        if (prime[i] == 0) {
            for (int j=i+i; j<1010101; j+=i) {
                prime[j] = 1;
            }
        }
    }
    memset(sgs, -1, sizeof sgs);
    sgs[0] = 0;
    sgs[1] = 1;
    for (int i=1; i<1010101; i++) {
        if (sgs[i] != -1) continue;
        vector<int> hist;
        int go = i;
        chk[go] = 1;
        hist.push_back(go);
        while (true) {
            int nxt = 0;
            int g = go;
            while (g) {
                nxt += (g % 10) * (g % 10);
                g /= 10;
            }
            if (sgs[nxt] == 1) {
                for (int i : hist) {
                    chk[i] = 0;
                    sgs[i] = 1;
                }
                break;
            }
            else if (sgs[nxt] == 0 || chk[nxt] == 1) {
                for (int i : hist) {
                    chk[i] = 0;
                    sgs[i] = 0;
                }
                break;
            }
            chk[nxt] = 1;
            hist.push_back(nxt);
            go = nxt;
        }
    }
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (prime[i] == 0 && sgs[i] == 1) cout << i << '\n';
    }
}