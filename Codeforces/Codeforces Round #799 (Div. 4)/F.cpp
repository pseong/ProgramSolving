#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi v(10);
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            v[a%10]++;
        }
        vi an;
        for (int i=0; i<10; i++) {
            for (int j=0; j<min(3, v[i]); j++) {
                an.push_back(i);
            }
        }
        n = an.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    for (int m : {3, 13, 23}) {
                        if (an[i] + an[j] + an[k] == m) {
                            goto g;
                        }
                    }
                }
            }
        }
        cout << "NO\n";
        continue;
        g:
        cout << "YES\n";
    }
}