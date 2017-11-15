#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

const int MN = 3000, MC = 100000;
int tab[MN][MN], n, m, k;

struct ZeroTable {
    vector<int> val, e;
    int n, ep;

    ZeroTable(int n_) : n(n_), ep(0) {
        val.resize(n, 0);
        e.resize(n, 0);
    }

    int get(int i) {
        if(ep == e[i]) return val[i];
        return 0;
    }

    void set(int i, int v) {
        e[i] = ep;
        val[i] = v;
    }

    void zero() {
        ep++;
    }
};

void read() {
    cin >> n >> m >> k;
    REP(i, n) REP(j, m) cin >> tab[i][j];
}

pair<ll, ll> row(int r, ZeroTable & zt) {
    ll cur = 0;
    zt.zero();
    REP(i, k) REP(j, k) {
        int val = tab[r + i][j];
        if(zt.get(val) == 0) cur++;
        zt.set(val, zt.get(val) + 1);
    }
    ll suma = cur, najw = cur;

    for(int c = 1; c < m - k + 1; c++) {
        REP(i, k) {
            int val = tab[r + i][c - 1];
            zt.set(val, zt.get(val) - 1);
            if(zt.get(val) == 0) cur--;
        }
        REP(i, k) {
            int val = tab[r + i][c + k - 1];
            if(zt.get(val) == 0) cur++;
            zt.set(val, zt.get(val) + 1);
        }
        suma += cur;
        najw = max(najw, cur);
    }
    return {suma, najw};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();

    ll suma = 0, najw = 0;
    ZeroTable zt(MC + 7);
    REP(r, n - k + 1) {
        auto p = row(r, zt);
        suma += p.first;
        najw = max(najw, p.second);
    }

    cout << najw << ' ' << suma << '\n';
}
