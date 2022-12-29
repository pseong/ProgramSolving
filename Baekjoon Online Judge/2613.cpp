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

int n, m, v[330];
int ans;
vector<int> res;

bool cal(int x) {
    int now = 0;
    int cnt = 0;
    vector<int> a;
    for (int i=0; i<n; i++) {
        if (now + v[i] <= x) now += v[i], cnt++;
        else {
            a.push_back(cnt);
            cnt = 1;
            now = v[i];
            if (now > x) return false;
        }
    }
    a.push_back(cnt);
    if (a.size() <= m) {
        ans = x;
        int need = m - (int)a.size();
        vector<int> b;
        for (int o : a) {
            while (need && o > 1) {
                b.push_back(1);
                need--;
                o--;
            }
            b.push_back(o);
        }
        res = b;
        return true;
    }
    else return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int lo = 1;
    int hi = 10000000;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cal(m)) {
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
}