#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;

const int MOD = 1000*1000*1000 + 7;

struct FaU {
    vector<int> v;
    int n;

    FaU(int l) : n(l) {
        v.resize(n);
        REP(i, n) v[i] = i;
    }

    int find(int x) { return (x == v[x]) ? x : (v[x] = find(v[x])); }
    int uni(int a, int b) {
        a = find(a); b = find(b);
        v[b] = a;
        return a;
    }
};

struct Sciana {
    int a, b, h;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    LL h;
    cin >> m >> n >> h;
    int l_scian = n*(m - 1) + m*(n - 1);

    vector<Sciana> s;
    s.reserve(l_scian);
    REP(i, m) REP(j, n-1) {
        int x;
        cin >> x;
        s.push_back(Sciana {i*n + j, i*n + j + 1, x});
    }
    REP(i, m-1) REP(j, n) {
        int x;
        cin >> x;
        s.push_back(Sciana {i*n + j, (i + 1)*n + j, x});
    }

    vector<int> ord(l_scian);
    REP(i, l_scian) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int a, int b){
        if(s[a].h == s[b].h) return a < b;
        return s[a].h < s[b].h;
    });

    FaU fau(m*n);
    vector<int> moz(m*n);
    for(int& x: moz) x = h + 1;

    for(int si: ord) {
        int a = s[si].a;
        int b = s[si].b;
        LL sh = s[si].h;
        a = fau.find(a); b = fau.find(b);
        if(a == b) continue;
        LL moz_a = moz[a];
        LL moz_b = moz[b];
        a = fau.uni(a, b);
        LL moz_ab = ((moz_a*moz_b - (h - sh)*(moz_b - 1) - (h - sh)*(moz_a - (h - sh)))%MOD + MOD)%MOD;
        moz[a] = moz_ab;
    }

    cout << moz[fau.find(0)] << '\n';
}
