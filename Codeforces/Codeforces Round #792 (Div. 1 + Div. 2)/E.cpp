#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            mp[a]++;
        }
        int cnt = 0;
        int i=0;
        for (; i<n; i++) {
            if (mp.find(i) == mp.end()) {
                if (cnt == k) break;
                cnt++;
            }
        }
        for (auto at : mp) {
            if (at.first > i) pq.push(at.second);
        }
        while (cnt && pq.size()) {
            if (cnt >= pq.top()) {
                cnt -= pq.top();
                pq.pop();
            }
            else break;
        }
        cout << pq.size() << '\n';
    }
}