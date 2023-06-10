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

map<char, int> mp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mp['A'] = 0;
    mp['B'] = 3;
    mp['C'] = 4;
    mp['D'] = 8;
    mp['E'] = 9;
    mp['F'] = 14;
    mp['G'] = 23;

    char p, q;
    cin >> p >> q;
    if (q > p) swap(p, q);
    cout << abs(mp[p] - mp[q]);
}