#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;
typedef pair<LL, LL> PLL;

const int MN = 1000*10, MA = 1000*1000*1000;

int get_rand(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(atoi(argv[1]));

    int n = get_rand(1, MN);
    int k = get_rand(1, n);
    cout << n << ' ' << k << '\n';

    int zapewniony = get_rand(1, MA - 1);
    vector<pair<int, int>> v(n);

    int a, b;
    REP(i, n) {
        if(i < k) {
            a = get_rand(1, zapewniony);
            b = get_rand(zapewniony + 1, MA);
        }
        else {
            a = get_rand(1, MA - 1);
            b = get_rand(a + 1, MA);
        }
        v[i] = {a, b};
    }

    random_shuffle(v.begin(), v.end());
    for(auto p: v) cout << p.first << ' ' << p.second << '\n';
}
