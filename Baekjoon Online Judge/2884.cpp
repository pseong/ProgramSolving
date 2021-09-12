#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int h, m;
    cin >> h >> m;
    
    if(m < 45) h = (h+23)%24;
    m = (m+15)%60;

    cout << h << ' ' << m;
}