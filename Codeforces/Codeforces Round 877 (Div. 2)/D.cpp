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

int n, q;
string s;
set<int> open, close;

void chk(int pos, int fg) {
    if (s[pos] == s[pos+1]) {
        if (s[pos] == '(') {
            if (fg == 1) open.insert(pos);
            else open.erase(pos);
        }
        else {
            if (fg == 1) close.insert(pos);
            else close.erase(pos);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> s;
    if (n%2) {
        for (int i=0; i<q; i++) no();
        return 0;
    }
    for (int i=0; i<n-1; i++) chk(i, 1);
    while (q--) {
        int x;
        cin >> x;
        x--;
        
        if (x < n-1) chk(x, 0);
        if (x > 0) chk(x-1, 0);
        s[x] ^= '(' ^ ')';
        if (x < n-1) chk(x, 1);
        if (x > 0) chk(x-1, 1);

        if (s[0] == ')' || s[n-1] == '(') {
            no();
            continue;
        }
        if (close.size() && (open.empty() || *open.begin() > *close.begin())) {
            no();
            continue;
        }
        if (open.size() && (close.empty() || *open.rbegin() > *close.rbegin())) {
            no();
            continue;
        }
        yes();
    }
}