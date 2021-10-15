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
    map<string, int> mp;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for(int i=0; i<n-1; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for(auto aut : mp) {
        if(aut.second&1) {
            cout << aut.first;
            break;
        }
    }
}