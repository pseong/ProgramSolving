#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int a[9]{0};
int ok[9]{0};

void show() {
    for(int i : v) {
        cout << a[i] << ' ';
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
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    func(m);
}