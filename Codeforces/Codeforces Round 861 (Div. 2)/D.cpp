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
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    if (n == 1 || k == 1) {
        cout << 0 << '\n';
        return 0;
    }
    ll ans = 0;
    vector<int> cnt(202020);
    deque<int> q;
    int sum = 0;
    for (int s=0; s<2; s++) {
        for (int i=s; i<n; i+=2) {
            if (q.size() && i+(q.back()-i)/2+k/2 >= n) {
                cnt[v[q.back()]]--;
                sum--;
                q.pop_back();
            }
            if (i+k-1 < n) {
                q.push_back(i+k-1);
                cnt[v[i+k-1]]++;
                sum++;
            }
            if (i > 0 && i < k/2) {
                q.push_front(k-1-i);
                cnt[v[k-1-i]]++;
                sum++;
            }
            ans += sum - cnt[v[i]];
            if (i >= k/2-1 && q.size()) {
                int p = q.front();
                q.pop_front();
                cnt[v[p]]--;
                sum--;
            }
        }
    }
    cout << ans << '\n';
}