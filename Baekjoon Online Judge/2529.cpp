#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int k;
char a[10];
bool ok[10]{0};
long long ans_mx = 0;
vector<int> mx;
long long ans_mn = 10000000000;
vector<int> mn;
vector<int> v;

void func(int index) {
    if(index == k+2) {
        long long res=0;
        for(int i=0; i<k+1; i++) {
            res += v[k+1-i]*pow(10,i);
        }
        if(ans_mx < res) {
            ans_mx = res;
            mx = v;
        }
        if(ans_mn > res) {
            ans_mn = res;
            mn = v;
        }
        return;
    }
    for(int i=0; i<=9; i++) {
        if(ok[i]) continue;
        if(v.back() < i && a[index-1] == '>') continue;
        if(v.back() > i && a[index-1] == '<') continue;
        ok[i] = 1;
        v.push_back(i);
        func(index+1);
        ok[i] = 0;
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    a[0] = '<';
    cin >> k;
    for(int i=1; i<=k; i++) {
        cin >> a[i];
    }
    v.push_back(-1);

    func(1);
    for(int i=1; i<=k+1; i++) {
        cout << mx[i];
    }
    cout << '\n';
    for(int i=1; i<=k+1; i++) {
        cout << mn[i];
    }
}