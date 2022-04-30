#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll sum_y = 0;
    ll sum_x = 0;
    ll left = 0;
    ll right = 0;
    ll pre = 0;
    priority_queue<ll> lo;
    priority_queue<ll, vector<ll>, greater<ll>> hi;
    unordered_map<ll, ll> mp;
    for (ll i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;

        if (lo.empty() || lo.top() >= y) {
            lo.push(y);
        }
        else hi.push(y);
        if (lo.size() > hi.size() + 1) {
            hi.push(lo.top());
            lo.pop();
        }
        else if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
        ll well = lo.top();
        if (i == 0) pre = well;

        ll gap = abs(pre - well);
        if (well < pre) {
            sum_y -= gap*left;
            left -= mp[well];
            right += mp[pre];
            sum_y += gap*right;
        }
        else if (well > pre) {
            sum_y -= gap*right;
            left += mp[pre];
            right -= mp[well];
            sum_y += gap*left;
        }
  
        pre = well;
        mp[y]++;
        if (y < well) left++;
        else if (y > well) right++;
        sum_y += abs(well - y);
        sum_x += abs(x);
        cout << well << ' ' << sum_x + sum_y << '\n';
    }
}