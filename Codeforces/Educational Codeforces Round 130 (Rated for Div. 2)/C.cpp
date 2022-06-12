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
        string s, t;
        cin >> s >> t;
        vector<int> scnt(3), tcnt(3);
        for (int i=0; i<n; i++) {
            scnt[s[i]-'a']++;
        }
        for (int i=0; i<n; i++) {
            tcnt[t[i]-'a']++;
        }
        if (scnt[0] != tcnt[0] || scnt[1] != tcnt[1] || scnt[2] != tcnt[2]) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) {
                bool f = false;
                if (s[i] == 'a' && t[i] == 'b') {
                    for (int k=i+1; k<n; k++) {
                        if (s[k] == 'b') {
                            swap(s[i], s[k]);
                            f = true;
                            break;
                        }
                        else if (s[k] != 'a') {
                            ok = false;
                            break;
                        }
                    }
                }
                else if (s[i] == 'b' && t[i] == 'c') {
                    for (int k=i+1; k<n; k++) {
                        if (s[k] == 'c') {
                            swap(s[i], s[k]);
                            f = true;
                            break;
                        }
                        else if (s[k] != 'b') {
                            ok = false;
                            break;
                        }
                    }
                }
                else {
                    ok = false;
                    break;
                }
                if (!f) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}