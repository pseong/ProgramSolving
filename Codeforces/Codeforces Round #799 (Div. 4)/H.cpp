#include <bits/stdc++.h>
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        map<int, vector<int>> mp;
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }
        vector<int> ans{ v[0], 0, 0, 1 };
        
        for (auto [b, q] : mp) {
            int res = 1;
            for (int l=0, r=1; r<(int) q.size(); r++) {
                int cal = 2*(r - l + 1) - (q[r] - q[l] + 1);
                if (cal < 1) {
                    l = r;
                }
                if (cal > ans[3]) {
                    ans = { b, q[l], q[r], cal };
                }
            }
        }
        
        cout << ans[0] << " " << ans[1]+1 << " " << ans[2]+1 << ' ' << "\n";
    }
}