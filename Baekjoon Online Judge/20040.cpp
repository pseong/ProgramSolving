#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[500010]{0};

int getParent(int i) {
    if(parent[i]==i) return i;
    return parent[i] = getParent(parent[i]);
}

int unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) {
        parent[a] = b;
        return 1;
    } else if(a<b) {
        parent[b] = a;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        int res=unionParent(a, b);
        if(!res) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}