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

bool comp(pair<int, char> l, pair<int, char> r) {
    if (l.first != r.first) return l.first > r.first;
    return l.second < r.second;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    string ans(m, '.');
    int ans2 = 0;
    for (int j=0; j<m; j++) {
        int cnt[300]{ 0 };
        for (int i=0; i<n; i++) {
            cnt[v[i][j]]++;
        }
        vector<pair<int, char>> lst;
        lst.push_back({cnt['A'], 'A'});
        lst.push_back({cnt['C'], 'C'});
        lst.push_back({cnt['G'], 'G'});
        lst.push_back({cnt['T'], 'T'});
        sort(lst.begin(), lst.end(), comp);
        ans[j] = lst[0].second;
        ans2 += n - lst[0].first;
    }
    cout << ans << '\n' << ans2 << ' ' << '\n';
}