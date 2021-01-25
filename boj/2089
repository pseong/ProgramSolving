#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<bool> vb;

    while(1) {
        if (n % 2 == 0) {
            vb.push_back(0);
            n = n / -2;
        } else {
            vb.push_back(1); 
            n = (n - 1) / -2;
        }
        if(n == 0) break;
    }

    for(auto it = vb.rbegin(); it != vb.rend(); it++)
        cout << *it;
}