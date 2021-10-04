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
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int parent[100]{0};

int getParent(int i) {
    if(parent[i]==i) return i;
    else return parent[i] = getParent(parent[i]);
}

void unionParent(int i, int j) {
    i = getParent(i);
    j = getParent(j);
    if(i<j) {
        parent[j] = i;
    } else {
        parent[i] = j;
    }
}

int findParent(int i, int j) {
    return getParent(i)==getParent(j);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m, g;
    cin >> n >> m >> g;
    vector<int> danger;
    for(int i=0; i<g; i++) {
        int a;
        cin >> a;
        danger.push_back(a);
    }

    for(int i=1; i<=60; i++) {
        parent[i] = i;
    }

    vector<int> party[100];
    for(int i=0; i<m; i++) {
        int nums;
        cin >> nums;
        for(int j=0; j<nums; j++) {
            int a;
            cin >> a;
            party[i].push_back(a);
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<party[i].size()-1; j++) {
            unionParent(party[i][j], party[i][j+1]);
        }
    }

    int ans=0;
    for(int i=0; i<m; i++) {
        bool flag=true;
        for(int j=0; j<party[i].size(); j++) {
            for(int k : danger) {
                if(findParent(k, party[i][j])) {
                    flag = false;
                }
            }
        }
        if(flag) ans++;
    }
    cout << ans;
}