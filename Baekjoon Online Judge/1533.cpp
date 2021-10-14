#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second

vector<vector<ll>> an(50, vector<ll>(50));
int n, s, e, t;

vector<vector<ll>> pow(vector<vector<ll>>& arr, int r) {
    if(r==1) return arr;
    if(r%2==1) {
        vector<vector<ll>> b(pow(arr, r-1));
        vector<vector<ll>> ret(50, vector<ll>(50));
        for(int i=0; i<50; i++) {
            for(int j=0; j<50; j++) {
                for(int k=0; k<50; k++) {
                    ret[i][j] += an[i][k]*b[k][j];
                    ret[i][j] %= 1000003;
                }
            }
        }
        return ret;
    } else {
        vector<vector<ll>> a(pow(arr, r/2));
        vector<vector<ll>> ret(50, vector<ll>(50));
        for(int i=0; i<50; i++) {
            for(int j=0; j<50; j++) {
                for(int k=0; k<50; k++) {
                    ret[i][j] += a[i][k]*a[k][j];
                    ret[i][j] %= 1000003;
                }
            }
        }
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> s >> e >> t;
    for(int i=4; i<n*5; i+=5) {
        for(int j=4; j<n*5; j+=5) {
            char a;
            cin >> a;
            int b=a-'0';
            if(b>1) {
                an[i][j-b+1] = 1;
                for(int k=1; k<=b-1; k++) {
                    an[j-b+k][j-b+k+1] = 1;
                }
            }
            else an[i][j] = b;
        }
    }
    /*
    for(int i=0; i<n*5; i++) {
        for(int j=0; j<n*5; j++) {
            cout << an[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
    cout << '\n';*/

    vector<vector<ll>> ab=pow(an, t);/*
    for(int i=0; i<n*5; i++) {
        for(int j=0; j<n*5; j++) {
            cout << ab[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << ab[s*5-1][e*5-1];
}