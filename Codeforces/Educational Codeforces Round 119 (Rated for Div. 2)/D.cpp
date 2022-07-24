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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        srt(v);
        if (v.back()%3 == 0) {
            bool other = false;
            for (int i=0; i<n; i++) {
                if (v[i]%3 != 0) other = true;
            }
            if (other) {
                cout << v.back()/3+1 << '\n';
            }
            else {
                cout << v.back()/3 << '\n';
            }
        }
        else if (v.back()%3 == 1) {
            bool one = false;
            bool nm1 = false;
            bool pertwo = false;
            for (int i=0; i<n; i++) {
                if (v[i] == 1) one = true;
                if (v[i] == v.back()-1) nm1 = true;
                if (v[i]%3 == 2) pertwo = true;
            }
            if (pertwo) {
                if (!one && !nm1) {
                    cout << v.back()/3+1 << '\n';
                }
                else {
                    cout << v.back()/3+2 << '\n';
                }
            }
            else {
                cout << v.back()/3+1 << '\n';
            }
        }
        else {
            bool perone = false;
            for (int i=0; i<n; i++) {
                if (v[i]%3 == 1) perone = true;
            }
            if (perone) {
                cout << v.back()/3+2 << '\n';
            }
            else {
                cout << v.back()/3+1 << '\n';
            }
        }
        g:
        continue;
    }
}