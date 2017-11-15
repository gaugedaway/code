#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int INF = 1000*1000*1000 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    REP(i, n) cin >> v[i].first >> v[i].second;

    int best;
    cin >> best;
    vector<int> rozw(k);
    REP(i, k) {
        cin >> rozw[i];
        rozw[i]--;
    }

    int a = -1, b = INF;
    for(int x: rozw) {
        a = max(a, v[x].first);
        b = min(b, v[x].second);
    }

    if(b - a >= best) return 0;
    else return 1;
}
