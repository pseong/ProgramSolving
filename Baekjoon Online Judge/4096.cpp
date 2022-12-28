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

void add(string& s) {
    int p = 1;
    for (int i=(int)s.size()-1; i>=0; i--) {
        int a = s[i] - '0' + p;
        if (a >= 10) {
            a = a % 10;
            p = 1;
        }
        else p = 0;
        s[i] = a + '0';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string s;
        cin >> s;
        if (s == "0") break;
        int cnt = 0;
        while (true) {
            string rs = s;
            reverse(rs.begin(), rs.end());
            if (s == rs) {
                cout << cnt << '\n';
                break;
            }
            add(s);
            cnt++;
        }
    }
    
}