#include <bits/stdc++.h>

using namespace std;

bool func(const pair<int, string>& p1, const pair<int, string>& p2) {
    return p1.first < p2.first;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, string>> v;

    for(int i = 1; i <= n; i++) {
        int x;
        string y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    stable_sort(v.begin(), v.end(), func);

    for(auto i : v)
        cout << i.first << ' ' << i.second <<'\n';
}