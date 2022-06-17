#include <bits/stdc++.h>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int go = 0;
        if (a < b) {
            swap(a, b);
            go = 1;
        }
        while (a > 0 || b > 0) {
            if (a > 0) cout << go;
            if (b > 0) cout << (go^1);
            a--;
            b--;
        }
        cout << '\n';
    }
}