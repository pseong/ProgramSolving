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

pi ans[202020];
int pre[202020], in[202020], idx[202020];
bool ok = true;

void dfs(int prel, int prer, int inl, int inr) {
    int i = idx[pre[prel]];
    if (i < inl || i > inr) {
        ok = false;
        return;
    }
    if (i-inl > 0) {
        ans[pre[prel]].first = pre[prel+1];
        dfs(prel+1, prel+i-inl, inl, i-1);
    }
    if (inr-i > 0) {
        ans[pre[prel]].second = pre[prel+i-inl+1];
        dfs(prel+i-inl+1, prer, i+1, inr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> pre[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> in[i];
        idx[in[i]] = i;
    }
    if (pre[1] != 1) {
        cout << -1;
        return 0;
    }
    dfs(1, n, 1, n);
    if (!ok) {
        cout << -1;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}