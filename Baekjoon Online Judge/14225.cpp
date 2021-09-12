#include <iostream>
#include <vector>

using namespace std;

int s[30]{0};
int n;
bool ok[2000001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }

    for(int i=1; i<(1<<n); i++) {
        int res=0;
        for(int j=0; j<n; j++) {
            if(i&(1<<j)) res += s[j]; 
        }
        ok[res] = 1;
    }

    int ans;
    for(int i=1; i<2000001; i++) {
        if(!ok[i]) {
            ans = i;
            break;
        }
    }
    cout << ans;
}