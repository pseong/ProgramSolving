#include <vector>
#include <iostream>

using namespace std;

int n, m;
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
        v.push_back(i);
        func(M-1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    func(m);
}