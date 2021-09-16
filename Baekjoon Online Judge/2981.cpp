#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b!=0) {
        a = a%b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int an[150]{0};
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    vector<int> diff;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            diff.push_back(abs(an[i]-an[j]));
        }
    }
    sort(diff.begin(), diff.end());
    int a=diff[0];
    for(int i=1; i<diff.size(); i++) {
        a=gcd(a, diff[i]);
    }
    vector<int> v;
    for(int i=1; i*i<=a; i++) {
        if(i*i==a) {
            v.push_back(i);
        }
        else if(a%i==0) {
            v.push_back(i);
            v.push_back(a/i);
        }
    }
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}