#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, m;
    cin >> a >> b >> m;

    int d10{ 0 };
    for(int i = m; i >= 1; i--) {
        int d;
        cin >> d;
        d10 += pow(a, i - 1) * d;
    }

    vector<int> vi;
    while(1) {
        int r = d10 % b;
        d10 = d10 / b;
        vi.push_back(r);
        if(d10 == 0) break;
    }

    for(auto it = vi.rbegin(); it != vi.rend(); it++)
        cout << *it << ' ';
}