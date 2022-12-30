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

int n;
vector<string> ans;
string now;

void go(int idx) {
    if (idx == n + 1) {
        string s;
        for (int i=0; i<(int)now.size(); i++) {
            if (now[i] != ' ') s.push_back(now[i]);
        }
        int cal = 0;
        int ing = 0;
        char oper = '+';
        for (int i=0; i<=(int)s.size(); i++) {
            if (i < (int)s.size() && s[i] >= '0' && s[i] <= '9') ing *= 10, ing += s[i] - '0';
            else {
                if (oper == '+') cal += ing;
                else cal -= ing;
                ing = 0;
                if (i < (int)s.size()) oper = s[i];
            }
        }
        if (cal == 0) ans.push_back(now);
        return;
    }
    now.push_back(' ');
    now.push_back(idx + '0');
    go(idx + 1);
    now.pop_back();
    now.pop_back();

    now.push_back('+');
    now.push_back(idx + '0');
    go(idx + 1);
    now.pop_back();
    now.pop_back();

    now.push_back('-');
    now.push_back(idx + '0');
    go(idx + 1);
    now.pop_back();
    now.pop_back();
}

void solve(int CASE) {
    cin >> n;
    now.clear();
    ans.clear();
    now.push_back('1');
    go(2);
    sort(ans.begin(), ans.end());
    for (string& s : ans) {
        cout << s << '\n';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}