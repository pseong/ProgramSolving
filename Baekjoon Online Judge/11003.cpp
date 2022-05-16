#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

deque<pll> q;
int n, l;
ll add(ll idx, ll x) {
    while (q.size() && q.back().second >= x) {
        q.pop_back();
    }
    q.push_back({idx, x});
    if (q.front().first == idx-l) q.pop_front();
    return q.front().second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    for (int i=0; i<n; i++) {
        ll x; cin >> x;
        cout << add(i, x) << ' ';
    }
}