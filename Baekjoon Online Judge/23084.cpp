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

int c[30]{0};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        c[s[i]-97]++;
    }

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s2;
        cin >> s2;
        int c2[2020][30]{0};

        for(int i=0; i<s2.size(); i++) {
            if(i!=0) {
                for(int j=0; j<30; j++) {
                    c2[i][j] = c2[i-1][j];
                }
            }
            c2[i][s2[i]-97]++;
        }

        if(s2.size()<s.size()) cout << "NO\n";
        else if(s2.size()==s.size()) {
            int diff=0;
            for(int i=0; i<30; i++) {
                if(c[i]!=c2[s2.size()-1][i]) {
                    diff += abs(c[i]-c2[s2.size()-1][i]);
                }
            }
            if(diff==2) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            bool flag=false;
            for(int i=0; i<=s2.size()-s.size(); i++) {
                int diff=0;
                
                if(i!=0) {
                    for(int j=0; j<30; j++) {
                        int a=c[j];
                        int b=c2[i+s.size()-1][j]-c2[i-1][j];
                        if(c[j]!=c2[i+s.size()-1][j]-c2[i-1][j]) {
                            diff += abs(c[j]-c2[i+s.size()-1][j]+c2[i-1][j]);
                        }
                    }
                } else {
                    for(int j=0; j<30; j++) {
                        int a=c[j];
                        int b=c2[i+s.size()-1][j];
                        if(c[j]!=c2[i+s.size()-1][j]) {
                            diff += abs(c[j]-c2[i+s.size()-1][j]);
                        }
                    }
                }

                if(diff==0||diff==2) {
                    flag = true;
                    break;
                }
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}