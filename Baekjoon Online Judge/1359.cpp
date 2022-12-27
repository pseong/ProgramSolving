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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> chk(n);
    for (int i=0; i<m; i++) {
        chk[i] = 1;
    }
    vector<vector<int>> v;
    sort(chk.begin(), chk.end());
    do {
        vector<int> lst;
        for (int i=0; i<n; i++) {
            if (chk[i]) lst.push_back(i + 1);
        }
        v.push_back(lst);
    } while (next_permutation(chk.begin(), chk.end()));
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i=0; i<(int)v.size(); i++) {
        for (int j=0; j<(int)v.size(); j++) {
            vector<int> a;
            set_intersection(v[i].begin(), v[i].end(), v[j].begin(), v[j].end(), inserter(a, a.begin()));
            if (a.size() >= k) cnt++;
        }
    }
    cout << fixed << setprecision(9) << cnt / double(v.size() * v.size()) << '\n';
}