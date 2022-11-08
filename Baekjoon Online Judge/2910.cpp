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

bool cmp(ti a, ti b) {
    if (get<0>(a) != get<0>(b)) {
        return get<0>(a) > get<0>(b);
    }
    return get<1>(a) < get<1>(b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    map<int, int> mp;
    map<int, int> idx;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (mp.find(a) == mp.end()) idx[a] = i;
        mp[a]++;
    }
    vector<ti> v;
    for (auto at : mp) {
        v.push_back({at.second, idx[at.first], at.first});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<(int)v.size(); i++) {
        int t = get<0>(v[i]);
        while (t--) {
            cout << get<2>(v[i]) << ' ';
        }
    }
}