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

    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    map<int, string> mp2;
    for (auto& at : mp) {
        mp2[at.second] = at.first;
    }
    auto it = mp2.begin();
    for (int i=0; i<n; i++) {
        cout << it->second << '\n';
        it++;
        if (it == mp2.end()) break;
    }
}