#include <iostream>
#include <algorithm>

using namespace std;

int an[100010]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    sort(an, an+n);
    int m;
    cin >> m;
    while(m--) {
        int a;
        cin >> a;
        int idx=lower_bound(an, an+n, a)-an;
        if(idx==n) cout << 0 << '\n';
        else {
            if(an[idx]==a) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}