#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string I, P;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int i=1; i<=T; i++) {
        string v;
        cin >> v;
        int sum = 0;
        for (int i=0; i<v.size(); i++) {
            sum += v[i] - '0';
        }

        int left = sum % 9;
        int add = 9 - left;
        add %= 9;
        int k = 0;
        if (add == 0) k = 1;
        for (; k<v.size(); k++) {
            if (v[k]-'0' > add) {
                break;
            }
        }

        cout << "Case #" << i << ": ";
        bool in = false;
        for (int j=0; j<v.size(); j++) {
            if (j==k) {
                in = true;
                cout << add;
            }
            cout << v[j];
        }
        if (!in) cout << add;
        cout << '\n';
    }
}