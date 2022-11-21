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

struct S{
    int h, c;
    bool operator<(S& r) {
        if (h == r.h) return c < r.c;
        return h > r.h;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<S> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].h >> v[i].c;
    }
    sort(v.begin(), v.end());
    multiset<int> z;
    for (int i=0; i<n; i++) {
        auto it = z.lower_bound(v[i].c);
        if (it == z.begin()) {
            z.insert(1);
            continue;
        }
        it--;
        int a = *it + 1;
        z.erase(it);
        z.insert(a);
    }
    cout << z.size() << '\n';
}