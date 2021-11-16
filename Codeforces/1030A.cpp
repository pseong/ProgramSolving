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

    int T;
    cin >> T;
    string s="EASY";
    while(T--) {
        int a;
        cin >> a;
        if(a==1) s="HARD";
    }
    cout << s;
}