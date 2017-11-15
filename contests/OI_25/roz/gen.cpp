#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

const int MN = 600, MK = 600, MC = 100*1000;

int get_rand(int a, int b) {
    return rand()%(b - a + 1) + a;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(atoi(argv[1]));
    
    int n = get_rand(1, MN);
    int m = get_rand(1, MN);
    int k = get_rand(1, min(MK, min(n, m)));
    
    cout << n << ' ' << m << ' ' << k << '\n';
    REP(i, n) {
        REP(j, m) cout << get_rand(1, MC) << ' ';
        cout << '\n';
    }
}
