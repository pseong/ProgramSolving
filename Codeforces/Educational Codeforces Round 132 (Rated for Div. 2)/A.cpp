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

    int T;
    cin >> T;
    for (int TT=1; TT<=T; TT++) {
        int n;
        cin >> n;
        vector<int> v(4);

        int a = 0;
        vector<int> chk(4);
        for (int i=1; i<=3; i++) {
            cin >> v[i];
            chk[v[i]] = 1;
        }
        for (int i=1; i<=3; i++) {
            if (chk[i] == 0) a = i;
        }
        if (v[v[a]] == 0) no();
        else yes();
    }
}