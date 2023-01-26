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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> odd, even;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i]%2 == 0) even.push_back(i + 1);
        else odd.push_back(i + 1);
    }
    if (odd.size() >= 3) {
        yes();
        cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << '\n';
        return;
    }
    if (odd.size() >= 1 && even.size() >= 2) {
        yes();
        cout << odd[0] << ' ' << even[0] << ' ' << even[1] << '\n';
        return;
    }
    no();
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