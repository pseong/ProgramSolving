#include <bits/stdc++.h>
using namespace std;

vector<int> manachers(vector<int> s) {
    vector<int> v(s.size());
    int m = 0, p = 0;
    int n = s.size();
    for (int i=0; i<n; i++) {
        if (i > m) v[i] = 0;
        else v[i] = min(m - i, v[2*p - i]);
        while (i - v[i] >= 0 && i + v[i] < n && s[i - v[i]] == s[i + v[i]]) v[i]++;
        v[i]--;
        if (m < i + v[i]) {
            p = i;
            m = i + v[i];
        }
    }
    return v;
}