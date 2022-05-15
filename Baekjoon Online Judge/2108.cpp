#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool comp(pi a, pi b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> an(n);
    unordered_map<int, int> mp;
    ll sum = 0;
    for (int i=0; i<n; i++) cin >> an[i], mp[an[i]]++, sum += an[i];
    cout << (int)round(double(sum)/n) << '\n';
    sort(an.begin(), an.end());
    cout << an[n/2] << '\n';
    vector<pi> v;
    for (auto at : mp) v.push_back({at.second, at.first});
    sort(v.begin(), v.end(), comp);
    if (v.size() > 1 && v[0].first == v[1].first)
    cout << v[1].second << '\n';
    else cout << v[0].second << '\n';
    cout << an.back() - an.front() << '\n';
}