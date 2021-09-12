#include <bits/stdc++.h>

using namespace std;

vector<int> edges[20010];
int colored[20010]{ 0 };
bool binary_graph = 1;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int a, p;
    cin >> a >> p;

    int idj[300000]{ 0 };

    int start = a;
    int n = 0;
    while(1) {
        n = 0;
        for(int i = 1; start / i != 0; i *= 10) {
            int d = (start % (i * 10)) / i;
            n += pow(d, p);
        }
        idj[start] = n;
        if(idj[n]) break;
        start = n;
    }

    int result = 0;
    int go = a;
    while(go != n) {
        result++;
        go = idj[go];
    }
    cout << result;
}