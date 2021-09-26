#include <iostream>
#include <algorithm>

using namespace std;

int an[10010]{0};
int cnt=0;

void f(int s, int e) {
    if(s>e) return;
    if(s==e) {
        cout << an[s] << '\n';
        return;
    }
    int idx=s+1;
    for(; idx<=e; idx++) {
        if(an[idx]>an[s]) {
            break;
        }
    }
    f(s+1, idx-1);
    f(idx, e);
    cout << an[s] << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a;
    while(cin >> a) {
        an[cnt] = a;
        cnt++;
    }

    f(0, cnt-1);
}