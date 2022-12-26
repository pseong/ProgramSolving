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
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<int> chk(n);
    for (int i=0; i<k; i++) {
        chk[i] = 1;
    }
    sort(chk.begin(), chk.end());
    set<string> st;
    do {
        vector<string> lst;
        for (int i=0; i<n; i++) {
            if (chk[i]) lst.push_back(to_string(v[i]));
        }
        sort(lst.begin(), lst.end());
        do {
            string str = "";
            for (int i=0; i<(int)lst.size(); i++) {
                str += lst[i];
            }
            st.insert(str);
        } while (next_permutation(lst.begin(), lst.end()));
    } while (next_permutation(chk.begin(), chk.end()));
    cout << st.size() << '\n';
}