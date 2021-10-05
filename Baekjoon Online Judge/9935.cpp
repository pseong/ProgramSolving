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
#include <list>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int table[50]{0};
list<char> li;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string s, s2;
    cin >> s >> s2;

    int j=0;
    for(int i=1; i<s2.size(); i++) {
        while(j!=0 && s2[i]!=s2[j]) {
            j = table[j-1];
        }
        if(s2[i]==s2[j]) {
            table[i] = j+1;
            j++;
        }
    }

    li.push_back('.');
    for(int i=0; i<s.size(); i++) {
        li.push_back(s[i]);
    }
    auto it = li.begin();
    it--;

    j = 0;
    for(auto it=li.begin(); it!=li.end(); it++) {
        while(j!=0 && *it!=s2[j]) {
            j = table[j-1];
        }
        if(*it==s2[j]) {
            if(j==s2.size()-1) {
                auto start=it;
                auto end=it;
                for(int k=0; k<j*2+2; k++) {
                    if(it==li.begin()) break;
                    it--;
                }
                for(int k=0; k<j; k++) start--;
                li.erase(start, ++end);
                j = 0;
            } else {
                j++;
            }
        }
    }

    if(li.size()==1) cout << "FRULA";
    else {
        for(it=++li.begin(); it!=li.end(); it++) {
            cout << *it;
        }
    }
}