#include <iostream>

using namespace std;

int n, m;
int ok[9]{ 0 };

void show() {
    for(int i=1; i <= 8; i++) {
        if(ok[i]) cout << i << ' ';
    }
    cout << '\n';
}

void func(int start, int M) {
    if(M < 1) {
        show();
        return;
    }
    for(int i=start+1; i<=n; i++) {
        if(ok[i]) continue;
        ok[i] = 1;
        func(i, M-1);
        ok[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    func(0, m);
}