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
    
    string s;
    cin >> s;
    int mid = 0;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == 'R') mid++;
    }
    int ans = 0;
    int r = (int)s.size() - 1;
    int left = 0;
    int right = 0;
    for (int l=0; l<(int)s.size(); l++) {
        while (right < left && l < r) {
            if (s[r] == 'R') mid--;
            else right++;
            r--;
        }
        if (right < left) break;
        if (mid) ans = max(ans, mid + left * 2);
        if (s[l] == 'R') mid--;
        else left++;
    }
    cout << ans << '\n';
}