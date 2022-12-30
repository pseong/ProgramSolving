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

int n, chk[100], ok;
string s;
vector<int> now;

void go(int idx) {
    if (ok) return;
    if (idx == (int)s.size()) {
        ok = 1;
        for (int x : now) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    for (int c=1; c<=min(2, (int)s.size()-idx); c++) {
        int x = stoi(s.substr(idx, c));
        if (x > n || chk[x]) continue;
        chk[x] = 1;
        now.push_back(x);
        go(idx + c);
        chk[x] = 0;
        now.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int sz = s.size();
    int now = 0;

    for (int i=1; i<=50; i++) {
        now += to_string(i).size();
        if (now == sz) {
            n = i;
            break;
        }
    }
    go(0);
}