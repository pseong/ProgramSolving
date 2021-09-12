#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void show() {
    for(int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}

void func(int start, int M) {
    if(M < 1) {
        show();
        return;
    }
    for(int i=start; i<=n; i++) {
        v.push_back(i);
        func(i, M-1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    func(1, m);
}