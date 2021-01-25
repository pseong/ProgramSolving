#include <bits/stdc++.h>

using namespace std;

int func(int a, int b){
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    int mxy = func(a, b);
    int mnb = a * b / mxy;
    cout << mxy << '\n';
    cout << mnb;
}