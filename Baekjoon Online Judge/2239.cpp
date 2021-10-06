#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <list>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

char board[9][9]{0};
int horizon[9]{0};
int vertical[9]{0};
int square[9]{0};
bool finish=false;

void go(int i, int j) {
    if(j==9) {
        if(i==8) {
            finish = true;
            return;
        }
        i = i+1;
        j = 0;
    }
    if(board[i][j]=='0') {
        for(int k=1; k<=9; k++) {
            if(!(horizon[i]&(1<<k)) && !(vertical[j]&(1<<k)) && !(square[i/3*3+j/3]&(1<<k))) {
                board[i][j] = k+'0';
                horizon[i] |= (1<<k);
                vertical[j] |= (1<<k);
                square[i/3*3+j/3] |= (1<<k);

                go(i, j+1);
                if(finish) return;

                board[i][j] = '0';
                horizon[i] &= ~(1<<k);
                vertical[j] &= ~(1<<k);
                square[i/3*3+j/3] &= ~(1<<k);
            }
        }
    } else {
        go(i, j+1);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(int i=0; i<9; i++) {
        horizon[i] = 1;
        vertical[i] = 1;
        square[i] = 1;
    }
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> board[i][j];
            horizon[i] |= (1<<board[i][j]-'0');
            vertical[j] |= (1<<board[i][j]-'0');
            square[i/3*3+j/3] |= (1<<board[i][j]-'0');
        }
    }

    go(0,0);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}