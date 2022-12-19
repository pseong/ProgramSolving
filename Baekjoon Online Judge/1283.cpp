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

int key[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i=0; i<n; i++) {
        getline(cin, s);
        for (int i=0; i<(int)s.size(); i++) {
            if (i == 0 || s[i-1] == ' ') {
                if (key[toupper(s[i])] == 0) {
                    key[toupper(s[i])] = 1;
                    s.insert(s.begin() + i + 1, ']');
                    s.insert(s.begin() + i, '[');
                    cout << s << '\n';
                    goto g;
                }
            }
        }
        for (int i=0; i<(int)s.size(); i++) {
            if (s[i] == ' ') continue;
            if (key[toupper(s[i])] == 0) {
                key[toupper(s[i])] = 1;
                s.insert(s.begin() + i + 1, ']');
                s.insert(s.begin() + i, '[');
                cout << s << '\n';
                goto g;
            }
        }
        cout << s << '\n';
        g:
        continue;
    }
}