#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m;
map<int, string> title;
vector<int> v;

int calc(int m) {
    return v[m];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        int j;
        cin >> s >> j;
        if (title[j] == "") {
            title[j] = s;
        }
        v.push_back(j);
    }

    for (int i=0; i<m; i++) {
        int input;
        cin >> input;
        int lo = 0;
        int hi = n-1;
        int ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cal = calc(mid);
            if (cal < input) {
                lo = mid + 1;
            }
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        cout << title[v[ans]] << '\n';
    }
}