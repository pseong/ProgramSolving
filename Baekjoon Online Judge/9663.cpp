#include <iostream>

using namespace std;

int n;
int ans=0;

bool col[20]{0};
bool hatch1[20]{0}; // '/'
bool hatch2[20]{0}; // '\'

void func(int x) {
    if(x==n+1) {
        ans++;
        return;
    }
    for(int y=1; y<=n; y++) {
        if(col[y] || hatch1[x+y] || hatch2[x-y+n]) continue;
        col[y] = 1;
        hatch1[x+y] = 1;
        hatch2[x-y+n] = 1;
        func(x+1);
        col[y] = 0;
        hatch1[x+y] = 0;
        hatch2[x-y+n] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    func(1);
    
    cout << ans;
}