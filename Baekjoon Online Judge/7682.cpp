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
vector<string> v(3);
vector<vector<string>> lst;

vector<string> now{{"...", "...", "..."}};
set<vector<string>> st;

bool chk() {
    for (int i=0; i<3; i++) {
        if (now[i][0] != '.' && now[i][0] == now[i][1] && now[i][1] == now[i][2]) return true;
        if (now[0][i] != '.' && now[0][i] == now[1][i] && now[1][i] == now[2][i]) return true;
    }
    if (now[0][0] != '.' && now[0][0] == now[1][1] && now[1][1] == now[2][2]) return true;
    if (now[0][2] != '.' && now[0][2] == now[1][1] && now[1][1] == now[2][0]) return true;
    return false;
}

void go(int idx) {
    if (idx == 9 || chk()) {
        st.insert(now);
        return;
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (now[i][j] == '.') {
                if (idx % 2 == 0) now[i][j] = 'X';
                else now[i][j] = 'O';
                go(idx + 1);
                now[i][j] = '.';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    go(0);

    while (true) {
        cin >> s;
        if (s == "end") break;
        v.resize(3);
        v[0] = s.substr(0, 3);
        v[1] = s.substr(3, 3);
        v[2] = s.substr(6, 3);
        if (st.count(v)) cout << "valid\n";
        else cout << "invalid\n";
    }
}