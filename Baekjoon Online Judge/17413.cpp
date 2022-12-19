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
    getline(cin, s);

    string now = "";
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == ' ' || s[i] == '<') {
            reverse(now.begin(), now.end());
            cout << now;
            now = "";
            if (s[i] == ' ' ) cout << ' ';
            if (s[i] == '<') {
                while (s[i] != '>') cout << s[i], i++;
                cout << s[i];
            }
        }
        else {
            now.push_back(s[i]);
        }
    }
    if (now.size()) {
        reverse(now.begin(), now.end());
        cout << now;
        now = "";
    }
}