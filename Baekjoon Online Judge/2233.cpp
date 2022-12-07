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

int n, a, b;
string str;
int now, flag;

int dfs() {
    int s = now;
    int cnt = 0;
    if ((s-1 == a || s-1 == b) && str[s-1] == '0') cnt++;
    while (str[now] == '0') {
        now++;
        cnt += dfs();
    }
    if (str[now] == '1' && (now == a || now == b)) cnt++;
    now++;
    if (!flag && (cnt == 1 && a == b || cnt == 2)) {
        flag = 1;
        cout << s << ' ' << now << '\n';
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> str >> a >> b;
    a--;
    b--;
    dfs();
}