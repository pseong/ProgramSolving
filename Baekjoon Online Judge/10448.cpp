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
    
    vector<int> v;
    int now = 0;
    for (int i=1; i<=50; i++) {
        now += i;
        v.push_back(now);
    }
    int n = v.size();
    vector<int> chk(1001);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (v[i] + v[j] + v[k] <= 1000) chk[v[i] + v[j] + v[k]] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        cout << chk[a] << '\n';
    }
}