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

bool ok(int l, int r) {
    if (l > r) return true;
    int i = l;
    if (s[i] == '1') {
        i++;
        int cnt = 0;
        while (i <= r && s[i] == '0') {
            i++;
            cnt++;
        }
        if (cnt < 2 || i > r) return false;
        cnt = 0;
        while (i <= r && s[i] == '1') {
            cnt++;
            i++;
        }
        return ((cnt >= 2 && ok(i-1, r)) || ok(i, r));
    }
    else if (s[i] == '0') {
        if (i < r && s[i+1] == '1') return ok(i + 2, r);
        else return false;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    if (ok(0, (int)s.size() - 1)) cout << "SUBMARINE\n";
    else cout << "NOISE\n";
}