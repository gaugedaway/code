#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;

const int MN = 100000;
int d1[4][4][4][4], d2[4][4][4][4];

inline int zysk(int x, int y, int z) {
    int l[4] = {0, 0, 0, 0};
    l[x] = 1; l[y] = 1; l[z] = 1;
    return l[1]+l[2]+l[3];
}

int main() {
    ios_base::sync_with_stdio(0);
    REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4)
        d1[i][j][k][l] = d2[i][j][k][l] = -1;
    d1[0][0][0][0] = d2[0][0][0][0] = 0;

    int n;
    cin >> n;
    REP(id, n) {
        char ch;
        cin >> ch;
        int c = ch;
        switch(c) {
        case 'M':
            c = 1;
            break;
        case 'B':
            c = 2;
            break;
        case 'F':
            c = 3;
            break;
        }

        REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4) {
            int dot = d1[i][j][k][l];
            if(dot != -1) {
                d2[j][c][k][l] = max(d2[j][c][k][l], dot + zysk(i, j, c));
                d2[i][j][l][c] = max(d2[i][j][l][c], dot + zysk(k, l, c));
            }
        }

        REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4) {
            d1[i][j][k][l] = d2[i][j][k][l];
        }
    }

    int best = 0;
    REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4) {
        best = max(best, d1[i][j][k][l]);
    }

    cout << best << '\n';
}

