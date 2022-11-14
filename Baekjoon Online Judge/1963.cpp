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

vector<int> prime(10000, 1);

void solve(int CASE) {
    int a, b;
    cin >> a >> b;
    queue<int> q;
    vector<int> chk(10001);
    chk[a] = 1;
    q.push(a);
    int cnt = 0;
    while (q.size()) {
        int t = q.size();
        while (t--) {
            int x = q.front();
            q.pop();
            if (x == b) {
                cout << cnt << '\n';
                return;
            }
            vector<int> z(4);
            for (int i=0; i<4; i++) {
                z[i] = x % 10;
                x /= 10;
            }
            for (int i=0; i<4; i++) {
                for (int j=0; j<10; j++) {
                    auto zz = z;
                    zz[i] = j;
                    int cal = zz[0] + zz[1] * 10 + zz[2] * 100 + zz[3] * 1000;
                    if (prime[cal] == 0 || chk[cal]) continue;
                    chk[cal] = 1;
                    q.push(cal);
                }
            }
        }
        cnt++;
    }
    cout << "Impossible\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<=9999; i++) {
        if (prime[i] == 1) {
            for (int j=i+i; j<=9999; j+=i) {
                prime[j] = 0;
            }
        }
    }
    for (int i=0; i<1000; i++) {
        prime[i] = 0;
    }
    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}