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
    
    ll n;
    cin >> n;
    vector<int> v(14);
    for (int i=0; i<14; i++) {
        cin >> v[i];
    }
    int x = n;
    int cntx = 0;
    for (int i=0; i<14; i++) {
        cntx += x / v[i];
        x %= v[i];
    }

    int y = n;
    int cnty = 0;
    for (int i=3; i<14; i++) {
        if (v[i-3] < v[i-2] && v[i-2] < v[i-1] && v[i-1] < v[i]) {
            y += cnty * v[i];
            cnty = 0;
        }
        else if (v[i-3] > v[i-2] && v[i-2] > v[i-1] && v[i-1] > v[i]) {
            cnty += y / v[i];
            y %= v[i];
        }
    }

    int a = x + cntx * v[13];
    int b = y + cnty * v[13];
    if (a > b) cout << "BNP";
    else if (a < b) cout << "TIMING";
    else cout << "SAMESAME";
}