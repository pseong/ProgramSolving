#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n, b;
    cin >> n >> b;

    vector<char> vc;
    while(1) {
        int r = n % b;
        n = n / b;
        if(r > 9) vc.push_back(r + 'A' - 10);
        else vc.push_back(r + '0');
        if(n == 0) break;
    }
    
    for(auto it = vc.rbegin(); it != vc.rend(); it++)
        cout << *it;
}