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

int n, chk;
vector<int> v, ans;

void go(int idx) {
    if (chk) return;
    if (idx == n) {
        ans = v;
        chk = true;
        return;
    }
    for (int i=1; i<=3; i++) {
        v[idx] = i;
        bool flag = true;
        for (int c=1; c<=(idx+1)/2; c++) {
            int a = idx - c*2 + 1;
            int b = idx - c + 1;
            bool ok = true;
            for (int j=0; j<c; j++) {
                if (v[a + j] != v[b + j]) ok = false;
            }
            if (ok) flag = false;
        }
        if (flag) go(idx + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    v.resize(n);
    ans.assign(n, 9);
    go(0);
    for (int x : ans) {
        cout << x;
    }
}