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

int table[1000010]{0};
vector<int> a1;
vector<int> a2;
vector<int> s1;
vector<int> s2;
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        a1.push_back(a);
    }   
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        a2.push_back(a);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    for(int i=0; i<n-1; i++) {
        if(a1[i+1]-a1[i]<0) {
            s1.push_back(a1[i+1]-a1[i]+360000);
        } else {
            s1.push_back(a1[i+1]-a1[i]);
        }
    }
    if(a1[0]-a1[n-1]<0) {
        s1.push_back(a1[0]-a1[n-1]+360000);
    } else {
        s1.push_back(a1[0]-a1[n-1]);
    }

    for(int i=0; i<n-1; i++) {
        if(a2[i+1]-a2[i]<0) {
            s2.push_back(a2[i+1]-a2[i]+360000);
        } else {
            s2.push_back(a2[i+1]-a2[i]);
        }
    }
    if(a2[0]-a2[n-1]<0) {
        s2.push_back(a2[0]-a2[n-1]+360000);
    } else {
        s2.push_back(a2[0]-a2[n-1]);
    }

    int j=0;
    for(int i=1; i<s2.size(); i++) {
        while(j>0 && s2[j]!=s2[i]) {
            j = table[j-1];
        }
        if(s2[j]==s2[i]) {
            table[i] = j+1;
            j++;
        }
    }

    bool possible=false;
    j=0;
    int i=0;
    for(int k=1; k<=2*n; k++) {
        while(j>0 && s1[i]!=s2[j]) {
            j = table[j-1];
        }
        if(s1[i]==s2[j]) {
            if(j==n-1) {
                possible = true;
                break;
            } else {
                j++;
            }
        }
        i++;
        if(i==n) i=0;
    }
    if(possible) cout << "possible";
    else cout << "impossible";
}