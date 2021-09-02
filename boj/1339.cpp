#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string inputs[10];
int n;
int check[30]{0};

int key[10]{0};

int ans=0;
void calc() {
    int sol=0;
    for(int i=0; i<n; i++) {
        int res=0;
        for(int j=0; j<inputs[i].size(); j++) {
            res *= 10;
            res += key[check[inputs[i][j]-'A']];
        }
        sol += res;
    }
    ans = max(ans, sol);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> inputs[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<inputs[i].size(); j++) {
            check[inputs[i][j]-'A'] = 1;
        }
    }
    int order=0;
    int cnt=0;
    for(int i=0; i<26; i++) {
        if(check[i]) {
            check[i] = order;
            order++;
            cnt++;
        }
    }

    vector<int> v;
    for(int i=0; i<10; i++) {
        v.push_back(i);
    }
    do {
        for(int i=0; i<cnt; i++) {
            key[i] = v[i];
        }
        calc();
    } while(next_permutation(v.begin(), v.end()));

    cout << ans;
}