#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> p(11, 1);
ll cnt(ll n, ll i, ll j) {
   if (p[1] & 1) for (int k = 1; k <= 10; k++) p[k] = p[k - 1] * 10;
   ll ret = n / p[i + 1] * p[i];
   ll t = n / p[i] % 10;
   if (!j && !ret) return 0; // if leading zero
   if (t > j) ret += p[i];
   else if (t == j) ret += n % p[i] + 1;
   if (j == 0) ret -= p[i];
   return ret;
}