#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<int> a;
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        a.push_back(i+1);
    }

    while (a.size() != 1) {
        for (int i=0; i<a.size(); i++) {
            a.erase(a.begin()+i);
        }
    }
    cout << a.front();
}