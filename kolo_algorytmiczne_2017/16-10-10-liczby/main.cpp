#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAX_B = 1000*1000*1000, SQRT_B = 32000;

LL rev_mod(LL a, LL b) {
    LL m = b;
    LL ax = 1, ay = 0,
       bx = 0, by = 1;
    while(a != 0 && b != 0) {
        if(a > b) {
            ax = ax - bx * (a / b);
            ay = ay - by * (a / b);
            a %= b;
        }
        else {
            bx = bx - ax * (b / a);
            by = by - ay * (b / a);
            b %= a;
        }
    }
    if(a == 0) return (bx%m + m)%m;
    else return (ax%m + m)%m;
}

void solve() {
    LL a, c, p;
    cin >> a >> c >> p;
    LL rev_a = rev_mod(a, p);
    LL rev_c = rev_mod(c, p);
    map<LL, LL> hm;
    LL x = 1;
    for(LL i = 0; i < SQRT_B; i++) {
        if(hm.find(x) == hm.end()) hm[x] = i;
        x = (x*rev_a)%p;
    }

    LL a_to_sqrt = x;
    x = rev_c;
    for(LL i = 0; i <= MAX_B; i += SQRT_B) {
        if(hm.find(x) != hm.end()) {
            cout << i + hm[x] << '\n';
            return;
        }
        x = (x*a_to_sqrt)%p;
    }

    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
}
