#include <bits/stdc++.h>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> table(26);
    int n; cin >> n;
    string ans(n+1, '0');
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cout << "? 2 1 " << i << endl;
        int res; cin >> res;
        if (res > cnt) {
            cout << "? 1 " << i << endl;
            char c; cin >> c;
            table[c-'a'] = i;
            ans[i] = c;
            cnt++;
        }
        else {
            vector<int> v;
            for (int j=0; j<26; j++) {
                if (table[j] != 0) v.push_back(table[j]);
            }
            assert(v.size() == cnt);
            sort(v.begin(), v.end());
            int x = v.back();
            int lo = 0;
            int hi = (int)v.size() - 1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                cout << "? 2 " << v[mid] << ' ' << i << endl;
                cin >> res;
                if (mid == cnt-res) {
                    lo = mid+1;
                }
                else {
                    x = v[mid-1];
                    hi = mid-1;
                }
            }
            for (int j=0; j<26; j++) {
                if (table[j] == x) {
                    ans[i] = j+'a';
                    table[j] = i;
                    break;
                }
            }
        }
    }
    cout << "! " << ans.substr(1) << '\n';
}