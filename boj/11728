#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a;
    vector<int> b;

    int n, m;
    cin >> n >> m;

    int d;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        a.push_back(d);
    }
    for(int i = 1; i <= m; i++) {
        cin >> d;
        b.push_back(d);
    }

    vector<int> result;

    int size_a = a.size();
    int size_b = b.size();

    int i = 0;
    int j = 0;

    while(i < size_a && j < size_b) {
        if(a[i] >= b[j]) {
            result.push_back(b[j]);
            j++;
        }
        else {
            result.push_back(a[i]);
            i++;
        }
    }
    while(i < size_a) {
        result.push_back(a[i]);
        i++;
    }
    while(j < size_b) {
        result.push_back(b[j]);
        j++;
    }
    for(int re : result) {
        cout << re << ' ';
    }
}