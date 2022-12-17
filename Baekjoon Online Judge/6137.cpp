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
    
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int l = 0;
    int r = n - 1;
    string ret;
    while (l <= r) {
        if (v[l] == v[r]) {
            int i = l;
            int j = r;
            while (i <= j && v[i] == v[j]) i++, j--;
            if (i > j) {
                ret.push_back(v[l]);
                l++;
            }
            else if (v[i] < v[j]) {
                ret.push_back(v[l]);
                l++;
            }
            else {
                ret.push_back(v[r]);
                r--;
            }
        }
        else if (v[l] < v[r]) {
            ret.push_back(v[l]);
            l++;
        }
        else {
            ret.push_back(v[r]);
            r--;
        }
    }
    int cnt = 0;
    for (int i=0; i<(int)ret.size(); i++) {
        cout << ret[i];
        cnt++;
        if (cnt % 80 == 0) {
            cout << '\n';
            cnt++;
        }
    }
}