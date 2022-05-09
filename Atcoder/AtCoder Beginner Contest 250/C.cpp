#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> idx(n+1);
    vector<int> vec(n+1);
    for (int i=1; i<=n; i++) {
        idx[i] = i;
        vec[i] = i;
    }
    for (int i=0; i<q; i++) {
        int a;
        cin >> a;
        if (idx[a] == n) {
            int left = vec[n-1];
            swap(idx[a], idx[left]);
            swap(vec[n], vec[n-1]);
        }
        else {
            int right = vec[idx[a]+1];
            swap(vec[idx[a]], vec[idx[a]+1]);
            swap(idx[a], idx[right]);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << vec[i] << ' ';
    }
}