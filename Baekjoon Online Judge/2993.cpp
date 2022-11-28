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
    int n = s.size();
    vector<string> ans;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n-1; j++) {
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1, j - i);
            string c = s.substr(j + 1, n - j - 1);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            string str = a + b + c;
            ans.push_back(str);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.front() << '\n';
}