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

vector<int> manachers(vector<int> s) {
    vector<int> v(s.size());
    int m = 0, p = 0;
    int n = s.size();
    for (int i=0; i<n; i++) {
        if (i > m) v[i] = 0;
        else v[i] = min(m - i, v[2*p - i]);
        while (i - v[i] >= 0 && i + v[i] < n && s[i - v[i]] == s[i + v[i]]) v[i]++;
        v[i]--;
        if (m < i + v[i]) {
            p = i;
            m = i + v[i];
        }
    }
    return v;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(-1);
        v.push_back(x);
    }
    v.push_back(-1);
    vector<int> res = manachers(v);
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a = a*2 - 1;
        b = b*2 - 1;
        int x = (a + b) / 2;
        cout << (res[x] >= b - x) << '\n';
    }
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}