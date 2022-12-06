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

vector<int> primes;
int chk[50505], sign[50505];

int cal(int x) {
    int res = 0;
    for (int i=1; i*i<=x; i++) {
        res += sign[i] * (x / (i * i));
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<=50000; i++) {
        if (chk[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<=50000; j+=i) {
                chk[j] = 1;
            }
        }
    }

    memset(sign, -1, sizeof sign);
    sign[1] = 1;
    for (int i=2; i<=50000; i++) {
        for (int j=2; j*j<=i; j++) {
            if (i % (j * j) == 0) {
                sign[i] = 0;
                break;
            }
        }
        if (sign[i] == 0) continue;
        int cnt = 0;
        int x = i;
        for (int j=0; j<(int)primes.size() && primes[j] <= x; j++) {
            if (x % primes[j] == 0) {
                cnt++;
                x /= primes[j];
            }
        }
        if (cnt%2 == 0) sign[i] = 1;
    }

    int k;
    cin >> k;

    int lo = 1;
    int hi = k*2;
    int ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (cal(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << '\n';
}