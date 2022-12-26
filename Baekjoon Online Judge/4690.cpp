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
    for (int i=2; i<=100; i++) {
        for (int j=2; j<=100; j++) {
            for (int k=j; k<=100; k++) {
                for (int l=k; l<=100; l++) {
                    if (i * i * i == j * j * j + k * k * k + l * l * l) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
                    }
                }
            }
        }
    }
}