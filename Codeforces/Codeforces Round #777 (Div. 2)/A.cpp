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
    while(T--) {
        int n;
        cin >> n;
        int sum = 0;
        if (n%3 == 1) {
            int c = 1;
            while (sum != n) {
                cout << c;
                sum += c;
                c ^= 1^2;
            }
        }
        else {
            int c = 2;
            while (sum != n) {
                cout << c;
                sum += c;
                c ^= 1^2;
            }
        }
        cout << '\n';
    }
}