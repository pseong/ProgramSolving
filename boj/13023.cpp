#include <iostream>
#include <vector>

using namespace std;

vector<int> v[2000];
int n, m;
bool visit[2000]{0};
bool ans=false;

void func(int num, int now) {
    if(num==1) {
        ans=true;
        return;
    }
    for(int vert : v[now]) {
        if(ans) break;
        if(visit[vert]) continue;
        visit[vert] = true;
        func(num-1, vert);
        visit[vert] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++) {
        if(ans) break;
        visit[i] = true;
        func(5, i);
        visit[i] = false;
    }
    cout << ans;
}