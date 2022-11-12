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

bool is_prime(int x) {
    if (x == 1) return false;
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool is_pal(int x) {
    int one = x;
    int two = 0;
    while (x) {
        two *= 10;
        two += x % 10;
        x /= 10;
    }
    return one == two;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (!is_pal(n) || !is_prime(n)) n++;
    cout << n << '\n';
}