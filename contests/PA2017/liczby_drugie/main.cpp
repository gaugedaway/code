/* Autor: Adam Bac
 * Zadanie: DRU
 * Potyczki Algorytmiczne 2017
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll str_to_int(const string & str) {
    ll ret = 0;
    for(char c: str) {
        ret *= 10;
        ret += c - '0';
    }
    return ret;
}

ll pow_mod(ll a, ll n, ll m) {
    if(n == 0) return 1;
    ll x = pow_mod(a, n / 2, m);
    x = (x * x) % m;
    if(n % 2 == 0) return x;
    else return (x * a) % m;
}

bool test_prime(ll p) {
    ll pm = p - 1;
    ll s = __builtin_ctz(pm);
    ll max_pow_of_2 = pm & (-pm);
    ll d = pm / max_pow_of_2;
    
    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37};
    for(ll prime: primes) {
        if(prime == p) return true;
        ll x = pow_mod(prime, d, p);
        if(x == 1 || x == p - 1) continue;
        bool cont = true;
        for(int i = 1; i < s && cont; i++) {
            x = (x * x) % p;
            if(x == 1) return false;
            if(x == p - 1) cont = false;
        }
        if(cont) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for(int div = 1; div < (int) str.size(); div++) {
        if(str[div] == '0') continue;
        if(test_prime(str_to_int(str.substr(0, div))) &&
           test_prime(str_to_int(str.substr(div)))) {
            cout << "TAK\n";
            return 0;
        }
    }

    cout << "NIE\n";
}
