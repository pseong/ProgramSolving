#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n*n);
    for(int i=0; i<n*n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-n];
}