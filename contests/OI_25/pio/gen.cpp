#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int MA = 10000, MN = 20;

int get_rand(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(atoi(argv[1]));

    int n = get_rand(1, MN);
    cout << n << '\n';
    REP(i, n) {
        cout << get_rand(-MA, MA) << ' ' << get_rand(-MA, MA) << '\n';
    }
}
