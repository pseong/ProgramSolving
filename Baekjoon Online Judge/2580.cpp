#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool c1[10][11]{0}; //행
bool c2[10][11]{0}; //열
bool c3[10][11]{0}; //사각형
int map[10][10]{0};

vector<pair<int ,int>> v;

bool ok=false;
void func(int cnt) {
    if(cnt==v.size()) {
        ok=true;
        return;
    }
    int i, j;
    tie(i, j) = v[cnt];
    for(int a=1; a<=9; a++) {
        if(c1[i][a] || c2[j][a] || c3[i/3*3+j/3][a]) continue;
        c1[i][a]=true;
        c2[j][a]=true;
        c3[i/3*3+j/3][a]=true;
        map[i][j]=a;
        func(cnt+1);
        if(ok) return;
        map[i][j]=0;
        c1[i][a]=false;
        c2[j][a]=false;
        c3[i/3*3+j/3][a]=false;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int a;
            cin >> a;
            if(a==0) v.push_back({i, j});
            else {
                map[i][j]=a;
                c1[i][a]=true;
                c2[j][a]=true;
                c3[i/3*3+j/3][a]=true;
            }
        }
    }
    func(0);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}