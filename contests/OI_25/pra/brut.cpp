#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

inline LL len(PLL a) {
    return a.first * a.first + a.second * a.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<PLL> wektory(n);
    REP(i, n) cin >> wektory[i].first >> wektory[i].second;

    LL najw = 0;

    for(int mask = 0; mask < (1<<n); mask++) {
        PLL suma = {0, 0};
        REP(i, n) if(mask & (1<<i)){
            suma.first += wektory[i].first;
            suma.second += wektory[i].second;
        }

        if(len(suma) > najw) {
            cout << "Nowa suma: " << len(suma) << endl;
            REP(i, n) if(mask & (1<<i)) cout << wektory[i].first << ' ' << wektory[i].second << endl;
        }

        najw = max(najw, len(suma));
    }

    cout << najw << '\n';
}
