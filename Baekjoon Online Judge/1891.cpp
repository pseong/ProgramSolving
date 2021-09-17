#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;
long long d, x, y;
string s;

pair<long long, long long> f(long long i, long long j, long long idx, long long gap) {
    char c=s[idx];
    if(c=='1') {
        j += gap/2;
    } else if(c=='2') {

    } else if(c=='3') {
        i += gap/2;
    } else if(c=='4') {
        j += gap/2;
        i += gap/2;
    }
    if(gap==2) return {i, j};
    return f(i, j, idx+1, gap/2);
}

string ans="";
long long i, j;
void f(long long a, long long b, long long gap) {
    char c;
    if(a+gap/2<=i) {
        a += gap/2;
        if(b+gap/2<=j) {
            b += gap/2;
            c = '4';
        } else {
            c = '3';
        }
    } else {
        if(b+gap/2<=j) {
            b += gap/2;
            c = '1';
        } else {
            c = '2';
        }
    }
    ans += c;
    if(gap==2) return;
    f(a, b, gap/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> d >> s >> x >> y;
    tie(i, j) = f(1, 1, 0, pow(2, d));
    i -= y;
    j += x;
    if(i<1||j<1||i>pow(2,d)||j>pow(2,d)) {
        cout << -1;
        return 0;
    }
    f(1, 1, pow(2, d));
    cout << ans;
}