#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
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
using pdd = pair<double, double>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

vector<vector<ll>> an{
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0},
};

vector<vector<ll>> pow(vector<vector<ll>>& arr, int r) {
    if(r==1) return arr;
    if(r%2==1) {
        vector<vector<ll>> b(pow(arr, r-1));
        vector<vector<ll>> ret(8, vector<ll>(8));
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                for(int k=0; k<8; k++) {
                    ret[i][j] += an[i][k]*b[k][j];
                    ret[i][j] %= 1000000007;
                }
            }
        }
        return ret;
    } else {
        vector<vector<ll>> a(pow(arr, r/2));
        vector<vector<ll>> ret(8, vector<ll>(8));
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                for(int k=0; k<8; k++) {
                    ret[i][j] += a[i][k]*a[k][j];
                    ret[i][j] %= 1000000007;
                }
            }
        }
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int d;
    cin >> d;
    cout << pow(an, d)[0][0];
}