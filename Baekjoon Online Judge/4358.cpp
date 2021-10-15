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

    map<string, int> mp;
    string str;
    int cnt=0;
    while(getline(cin, str)) {
        cnt++;
        mp[str]++;
    }
    for(auto a : mp) {
        cout << a.first << ' ';
        cout << fixed << setprecision(4) << (((double)a.second/cnt)*100) << '\n';
    }
}