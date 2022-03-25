#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> an;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        an.clear();
        an.resize(n);
        bool one = false;
        bool zero = false;
        bool two = false;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            an[i] = a;
            if (a==0) zero = true;
            else if(a==1) one = true;
            else if(a==2) two = true;
        }
        sort(an.begin(), an.end());
        an.erase(unique(an.begin(), an.end()), an.end());

        if (!one) {
            cout << "YES\n";
            continue;
        }

        if (zero) {
            cout << "NO\n";
            continue;
        }

        if (two) {
            cout << "NO\n";
            continue;
        }

        int pre = 1;
        bool good = true;
        for (int i=1; i<an.size(); i++) {
            if (an[i]-pre == 1) {
                good = false;
                break;
            }
            pre = an[i];
        }

        if (good) cout << "YES\n";
        else cout << "NO\n";
    }
}