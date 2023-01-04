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

int v[2000][2000];

int f(int x, int y, int a, int b) {
    int sz = a - x;
    if (sz == 1) return v[x][y];
    vector<int> lst;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            lst.push_back(f(x + i*sz/2, y + j*sz/2, x + (i+1)*sz/2, y + (j+1)*sz/2));
        }
    }
    sort(lst.begin(), lst.end());
    assert(lst.size() == 4);
    return lst[2];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    cout << f(0, 0, n, n) << '\n';
}