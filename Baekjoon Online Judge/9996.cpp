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
    
    int n;
    cin >> n;
    string t;
    cin >> t;
    int idx = 0;
    for (int i=0; i<(int)t.size(); i++) {
        if (t[i] == '*') idx = i;
    }
    while (n--) {
        string s;
        cin >> s;
        bool ok = true;
        if ((int)s.size() < (int)t.size() - 1) ok = false;
        for (int i=0; i<idx; i++) {
            if (i >= s.size() || s[i] != t[i]) {
                ok = false;
                break;
            }
        }
        for (int i=idx+1; i<(int)t.size(); i++) {
            int j = (int)s.size() - (int)t.size() + i;
            if (j >= (int)s.size() || s[j] != t[i]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "DA\n";
        else cout << "NE\n";
    }
}