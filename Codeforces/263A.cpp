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

    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            int a;
            cin >> a;
            if(a==1) {
                cout << abs(3-i)+abs(3-j);
            }
        }
    }
}