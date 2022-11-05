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

bool cmp(string& l, string& r) {
    if (l.size() != r.size()) {
        return l.size() < r.size();
    }
    int a = 0;
    int b = 0;
    for (int i=0; i<(int)l.size(); i++) {
        if (l[i] >= '1' && l[i] <= '9') a += l[i] - '0';
    }
    for (int i=0; i<(int)r.size(); i++) {
        if (r[i] >= '1' && r[i] <= '9') b += r[i] - '0';
    }
    if (a != b) {
        return a < b;
    }
    return l < r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<n; i++) {
        cout << v[i] << '\n';
    }
}