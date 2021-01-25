#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int p[10010]{ 0 };

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    int smx[10010]{ 0 };
    int result[10010]{ 0 };

    smx[1] = p[1];
    smx[2] = p[1] + p[2];
    result[1] = smx[1];
    result[2] = smx[2];

    for(int i = 3; i <= n; i++) {
        smx[i] = max(smx[i - 2] + p[i], result[i - 3] + p[i - 1] + p[i]);
        result[i] = max(smx[i], smx[i - 1]);
    }

    cout << result[n];
}