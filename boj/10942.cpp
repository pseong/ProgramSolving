#include <iostream>

using namespace std;

bool pal[3000][3000]{0};
int an[3000]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }

    for(int i=1; i<=n; i++) {
        int go=i;
        int back=i;
        while(go<=n && back>=1 && an[go]==an[back]) {
            pal[back][go] = 1;
            go++;
            back--;
        }
    }

    for(int i=1; i<=n-1; i++) {
        int go=i+1;
        int back=i;
        while(go<=n && back>=1 && an[go]==an[back]) {
            pal[back][go] = 1;
            go++;
            back--;
        }
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << pal[a][b] << '\n';
    }
}