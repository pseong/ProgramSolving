#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

bool leaf[100010];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }
    for(auto a : mp) {
        if(a.second==1) leaf[a.first] = true;
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int t, k;
        cin >> t >> k;
        if(t==2) cout << "yes\n";
        else {
            if(leaf[k]) cout << "no\n";
            else cout << "yes\n";
        }
    }
}