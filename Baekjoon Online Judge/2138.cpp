#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;

void flip(vector<int>& an, int p) {
    for(int i=p-1; i<=p+1; i++) {
        if (i<1 || i>n) continue;
        an[i] = 1-an[i];
    }
}

pair<bool, int> go(vector<int> an, vector<int>& bn) {
    int ans = 0;
    for (int i=2; i<=n; i++) {
        if (an[i-1] != bn[i-1]) {
            ans++;
            flip(an, i);
        }
    }

    if (an[n] == bn[n]) return {1, ans};
    else return {0, ans};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> an(n+1);
    vector<int> bn(n+1);

    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
        an[i+1] = s[i]-'0';
    }
    cin >> s;
    for (int i=0; i<n; i++) {
        bn[i+1] = s[i]-'0';
    }

    auto ret1 = go(an, bn);

    flip(an, 1);
    auto ret2 = go(an, bn);
    ret2.second += 1;

    if (!ret1.first && !ret2.first) {
        cout << -1;
    }
    else if (!ret1.first) {
        cout << ret2.second;
    }
    else if (!ret2.first) {
        cout << ret1.second;
    }
    else {
        cout << min(ret1.second, ret2.second);
    }
}