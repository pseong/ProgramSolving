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

int h, y;
int ans;

void go(int x, int now) {
    ans = max(ans, now);
    if (x + 1 <= y) go(x + 1, now * 1.05);
    if (x + 3 <= y) go(x + 3, now * 1.2);
    if (x + 5 <= y) go(x + 5, now * 1.35);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> h >> y;
    if (y == 0) {
        cout << h << '\n';
        return 0;
    }
    go(0, h);
    cout << ans << '\n';
}