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

bool chk[11];
int v[1010];

bool ok(int x) {
    while (x) {
        if (chk[x%10] == 0) return false;
        x /= 10;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        chk[a] = 1;
    }
    int ans = 0;
    int a = pow(10, v[0]-1);
    int b = pow(10, v[0]);
    int c = pow(10, v[1]-1);
    int d = pow(10, v[1]);
    for (int i=a; i<b; i++) {
        for (int j=c; j<d; j++) {
            if (ok(i) == 0 || ok(j) == 0) continue;
            int x = i;
            int y = j;
            int idx = 2;
            bool k = true;
            int Y = y;

            int X = x * y;
            int cnt = 0;
            while (X) {
                if (chk[X%10] == 0) k = false;
                cnt++;
                X /= 10;
            }
            if (cnt != v[n-1]) k = false;

            while (Y) {
                int z = Y % 10;
                int X = x * z;
                int cnt = 0;
                while (X) {
                    if (chk[X%10] == 0) k = false;
                    cnt++;
                    X /= 10;
                }
                if (cnt != v[idx]) k = false;
                Y /= 10;
                idx++;
            }
            if (k) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}