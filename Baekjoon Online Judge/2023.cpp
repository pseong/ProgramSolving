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

bool prime(int x) {
    if (x == 0 || x == 1) return false;
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int n;
vector<int> ans;

void go(int idx, int now) {
    if (idx == n) {
        ans.push_back(now);
        return;
    }
    for (int i=(idx == 0 ? 1 : 0); i<=9; i++) {
        if (prime(now * 10 + i)) go(idx + 1, now * 10 + i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    go(0, 0);
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << '\n';
    }
}