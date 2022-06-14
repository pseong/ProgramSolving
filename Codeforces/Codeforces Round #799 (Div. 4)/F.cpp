#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool f(vector<int>& v, int go) {
    for (int i=0; i<(int)v.size()-2; i++) {
        if (i>0 && v[i] == v[i-1]) continue;
        int j = i+1;
        int k = (int)v.size()-1;
        while (j < k) {
            int sum = v[i] + v[j] + v[k];
            if (sum == go) return true;
            else if (sum > go) k--;
            else j++;
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
            v[i] %= 10;
        }
        sort(v.begin(), v.end());
        if (f(v, 3) || f(v, 13) || f(v, 23)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}