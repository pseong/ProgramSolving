#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> p(10010);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    vector<int> smx(10010);

    smx[1] = p[1];
    smx[2] = p[1] + p[2];
    smx[3] = max({p[1] + p[2], p[1] + p[3], p[2] + p[3]});

    for(int i = 4; i <= n; i++) {
        smx[i] = max({smx[i - 2] + p[i], smx[i - 3] + p[i - 1] + p[i], smx[i - 4] + p[i - 1] + p[i]});
    }

    cout << max(smx[n], smx[n-1]);
}