#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[100010];
int level[100010]{ 0 };

void mklv(int n, int lv) {
    level[n] = lv;
    for(int i : vec[n]) {
        if(level[i]) continue;
        else mklv(i, lv + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    mklv(1, 1);

    for(int i = 2; i <= n; i++) {
        int parent = 100010;
        for(int j : vec[i]) {
            if(level[j] < level[i]) {
                parent = j;
                break;
            }
        }
        cout << parent << '\n';
    }
}