#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> pre;
vector<int> v;
int a[9]{0};
int ok[9]{0};

void show() {
    if(v == pre) return;
    pre = v;
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
    int pre = 0;
    for(int i=start; i<=n; i++) {
        if(ok[i]) continue;
        if(a[pre] == a[i]) continue;
        ok[i] = 1;
        v.push_back(a[i]);
        func(i, M-1);
        v.pop_back();
        ok[i] = 0;
        pre = i;
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
    func(1, m);
}