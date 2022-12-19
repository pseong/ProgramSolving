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

string s;
int chk[110];

void f(int l, int r) {
    if (l > r) return;
    int x = min_element(s.begin() + l, s.begin() + r + 1) - s.begin();
    chk[x] = 1;
    for (int i=0; i<(int)s.size(); i++) {
        if (chk[i]) cout << s[i];
    }
    cout << '\n';
    f(x + 1, r);
    f(l, x - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    f(0, (int)s.size() - 1);
}