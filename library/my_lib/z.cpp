#include <bits/stdc++.h>
using namespace std;

vector<int> z(string& s) {
    int n = s.size();
    vector<int> v(n);
    v[0] = n;
    int m = 0, p = 0;
    for (int i=1; i<n; i++) {
        if (i <= m) v[i] = min(m - i, v[i-p]);
        while (i + v[i] < n && s[i + v[i]] == s[v[i]]) v[i]++;
        if (i + v[i] > m) {
            m = i + v[i];
            p = i;
        }
    }
    return v;
}