#include <bits/stdc++.h>

using namespace std;

int n, m;
int ok[9]{ 0 };
vector<int> v;

void show() {
    for(int a : v) {
        cout << a << ' ';
    }
    cout << '\n';
}

void func(int M) {
    if(M < 1) {
        show();
        return;
    }
    for(int i=1; i<=n; i++) {
        if(ok[i]) continue;
        ok[i] = 1;
        v.push_back(i);
        func(M-1);
        v.pop_back();
        ok[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    func(m);
}