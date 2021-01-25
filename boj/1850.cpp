#include <bits/stdc++.h>

using namespace std;

long long func(long long a, long long b){
    long long r;
	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long mxy = func(a, b);
    while(mxy--) {
        putchar('1');
    }
}