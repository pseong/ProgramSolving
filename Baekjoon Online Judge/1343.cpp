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
    int n = s.size();
    for (int i=0; i<n; i++) {
        if (s[i] == '.') continue;
        if (i + 3 < n && s[i] == 'X' && s[i+1] == 'X' && s[i+2] == 'X' && s[i+3] == 'X') {
            for (int j=0; j<4; j++) {
                s[i+j] = 'A';
            }
            i += 3;
            continue;
        }
        else if (i + 1 < n && s[i] == 'X' && s[i+1] == 'X') {
            s[i] = 'B';
            s[i + 1] = 'B';
            i += 1;
            continue;
        }
        else {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << s << '\n';
}