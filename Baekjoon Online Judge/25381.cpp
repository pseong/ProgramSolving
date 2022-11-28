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

    string s;
    cin >> s;
    queue<int> a, b;
    int ans = 0;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == 'A') a.push(i);
        else if (s[i] == 'B') b.push(i);
        else if (s[i] == 'C' && b.size()) ans++, b.pop();
    }
    while (a.size() && b.size()) {
        if (a.front() < b.front()) ans++, a.pop(), b.pop();
        else b.pop();
    }
    cout << ans << '\n';
}