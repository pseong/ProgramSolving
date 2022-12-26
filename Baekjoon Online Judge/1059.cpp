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
    
    int l;
    cin >> l;
    vector<int> v(l);
    for (int i=0; i<l; i++) {
        cin >> v[i];
    }
    int n;
    cin >> n;
    v.push_back(0);
    sort(v.begin(), v.end());
    int res = 0;
    for (int i=1; i<(int)v.size(); i++) {
        int g = v[i] - 1 - v[i-1];
        if (g <= 0) continue;
        res += (g - 1) * g / 2;
    }
    v.push_back(n);
    sort(v.begin(), v.end());
    for (int i=1; i<(int)v.size(); i++) {
        int g = v[i] - 1 - v[i-1];  
        if (g <= 0) continue;
        res -= (g - 1) * g / 2;
    }
    cout << res << '\n';
}