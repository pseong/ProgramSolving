#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int a[101010];
const int sqrtN = 350;
vector<int> v[310];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        v[i/sqrtN].push_back(a[i]);
    }
    for (int i=0; i<300; i++) {
        sort(v[i].begin(), v[i].end());
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what==2) {
            int i, j, k;
            cin >> i >> j >> k;
            i--; j--;
            if (i/sqrtN == j/sqrtN) {
                int cnt = 0;
                for (int x=i; x<=j; x++) {
                    if (a[x] > k) cnt++;
                }
                cout << cnt << '\n';
            }
            else {
                int cnt = 0;
                while (i%sqrtN != 0) {
                    if (a[i] > k) cnt++;
                    i++;
                }
                while (j%sqrtN != sqrtN-1) {
                    if (a[j] > k) cnt++;
                    j--;
                }
                for (int x=i/sqrtN; x<=j/sqrtN; x++) {
                    cnt += v[x].end() - upper_bound(v[x].begin(), v[x].end(), k);
                }
                cout << cnt << '\n';
            }
        }
        else {
            int i, k;
            cin >> i >> k;
            i--;
            for (int x=0; x<v[i/sqrtN].size(); x++) {
                if (v[i/sqrtN][x] == a[i]) {
                    v[i/sqrtN].erase(v[i/sqrtN].begin()+x);
                    break;
                }
            }
            bool in = false;
            for (int x=0; x<v[i/sqrtN].size(); x++) {
                if (v[i/sqrtN][x] > k) {
                    v[i/sqrtN].insert(v[i/sqrtN].begin()+x, k);
                    in = true;
                    break;
                }
            }
            if (!in) v[i/sqrtN].push_back(k);
            a[i] = k;
        }
    }
}