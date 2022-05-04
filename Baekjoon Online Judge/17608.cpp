#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int, int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        while (v.size() && v.back() <= a) {
            v.pop_back();
        }
        v.push_back(a);
    }
    cout << v.size();
}