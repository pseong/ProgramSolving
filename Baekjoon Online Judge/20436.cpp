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

int when[200];
string s[3] = {"qwertyuiop", "asdfghjkl0", "zxcvbnm000"};
string s2[3] = {"yuiop", "hjkl0", "bnm00"};
pi ptr[200], p[2];

int dist(pi a, pi b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0; i<3; i++) {
        for (int j=0; j<10; j++) {
            ptr[s[i][j]] = {i, j};
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<5; j++) {
            when[s2[i][j]] = 1;
        }
    }
    
    char a, b;
    cin >> a >> b;
    p[0] = ptr[a];
    p[1] = ptr[b];
    string str;
    cin >> str;
    int ans = str.size();
    for (int i=0; i<(int)str.size(); i++) {
        ans += dist(p[when[str[i]]], ptr[str[i]]);
        p[when[str[i]]] = ptr[str[i]];
    }
    cout << ans << '\n';
}