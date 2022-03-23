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
        ll first = 0;
        ll second = 0;
        cin >> first >> second;
        if (second > first) swap(first, second);
        for (int i=3; i<=n; i++) {
            int a;
            cin >> a;
            if (a > first) {
                second = first;
                first = a;
            }
            else if (a > second) {
                second = a;
            }
        }
        cout << first + second << '\n';
    }
}