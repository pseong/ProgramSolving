#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;

bool f(vector<int>& an) {
    for (int i=1; i<n; i++) {
        if (an[i] - an[i-1] > 1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        vector<int> an(n, 0);
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        int one = count(an.begin(), an.end(), 1);
        if (one != 1) {
            cout << "NO\n";
            continue;
        }
        int a = find(an.begin(), an.end(), 1) - an.begin();
        rotate(an.begin(), an.begin() + a, an.end());

        cout << (f(an) ? "YES" : "NO") << '\n';
    }
}