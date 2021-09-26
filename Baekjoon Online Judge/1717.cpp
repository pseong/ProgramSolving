#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int parent[1000010]{0};

int getParent(int v) {
    if(parent[v]==v) return v;
    return parent[v] = getParent(parent[v]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=1000000; i++) {
        parent[i] = i;
    }
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==0) {
            unionParent(b, c);
        } else {
            cout << (findParent(b, c) ? "YES" : "NO") << '\n';
        }
    }
}