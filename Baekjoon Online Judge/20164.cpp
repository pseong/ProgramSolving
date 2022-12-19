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

pi f(int n) {
    string s = to_string(n);
    int cnt = 0;
    for (int i=0; i<(int)s.size(); i++) {
        if ((s[i]-'0') % 2) cnt++;
    }
    if (s.size() == 1) return {cnt, cnt};
    if (s.size() == 2) {
        pi ret = {1e9, 0};
        for (int i=0; i<(int)s.size()-1; i++) {
            string s1 = s.substr(0, i+1);
            string s2 = s.substr(i+1);
            pi a1 = f(stoi(s1) + stoi(s2));
            ret.first = min(ret.first, a1.first);
            ret.second = max(ret.second, a1.second);
        }
        return {ret.first + cnt, ret.second + cnt};
    }
    else {
        pi ret = {1e9, 0};
        for (int i=0; i<(int)s.size()-2; i++) {
            for (int j=i+1; j<(int)s.size()-1; j++) {
                string s1 = s.substr(0, i+1);
                string s2 = s.substr(i+1, j-i);
                string s3 = s.substr(j+1);
                pi a1 = f(stoi(s1) + stoi(s2) + stoi(s3));
                ret.first = min(ret.first, a1.first);
                ret.second = max(ret.second, a1.second);
            }
        }
        return {ret.first + cnt, ret.second + cnt};
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    pi p = f(n);
    cout << p.first << ' ' << p.second << '\n';
}