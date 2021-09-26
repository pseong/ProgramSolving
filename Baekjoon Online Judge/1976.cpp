#include <iostream>

using namespace std;

int parent[500]{0};

int getParent(int a) {
    if(parent[a]==a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) parent[a] = b;
    else parent[b] = a;
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int a;
            cin >> a;
            if(a) unionParent(i, j);
        }
    }
    int a;
    int pre;
    cin >> pre;
    while(cin >> a) {
        if(!findParent(a, pre)) {
            cout << "NO";
            return 0;
        }
        pre = a;
    }
    cout << "YES";
}