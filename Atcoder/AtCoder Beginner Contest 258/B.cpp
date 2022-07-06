#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<string> ans;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int x=-1; x<=1; x++) {
                for (int y=-1; y<=1; y++) {
                    if (x == 0 && y == 0) continue;
                    string now;
                    int a = i;
                    int b = j;
                    for (int k=0; k<n; k++) {
                        now.push_back(s[a][b]);
                        a = (a + x + n) % n;
                        b = (b + y + n) % n;
                    }
                    ans.push_back(now);
                }
            }
        }
    }
    srtrev(ans);
    cout << ans.front() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}