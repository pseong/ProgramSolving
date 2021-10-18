#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int xorr(int n) {
	int m = n % 4;
	if (m == 0) return n;
	if (m == 1) return 1;
	if (m == 2) return n + 1;
	return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        int x=xorr(a-1)^0;

        if(x==b) {
            cout << a << '\n';
        }
        else {
            x ^= b;
            if(x==a) {
                cout << a+2 << '\n';
            }
            else {
                cout << a+1 << '\n';
            }
        }
    }
}