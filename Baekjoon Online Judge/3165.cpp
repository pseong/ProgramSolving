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

void add(string& s, int j, int k) {
    int up = k;
    for (int i=j; i>=0; i--) {
        int a = s[i] - '0' + up;
        s[i] = a % 10 + '0';
        up = a / 10;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int k;
    cin >> s >> k;
    while (s.size() < 16) s.insert(s.begin(), '0');
    add(s, s.size()-1, 1);
    while (true) {
        int cnt = 0;
        for (int i=0; i<(int)s.size(); i++) {
            if (s[i] == '5') cnt++;
        }
        if (cnt >= k) {
            cout << stoll(s) << '\n';
            return 0;
        }
        for (int i=(int)s.size()-1; i>=0; i--) {
            if (s[i] != '5') {
                if (s[i] < '5') add(s, i, '5' - s[i]);
                else add(s, i, 10 + '0' - s[i]);
                break;
            }
        }
    }
}