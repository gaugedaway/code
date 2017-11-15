#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;

const int MM = 2*100*1000, MN = 1000*1000, BASE = (1<<20);
LL tr[2*BASE];
int len, m, n;
char out_str[MN];
pair<int, int> dopiski[MM];
string str;

struct Tree {
    int za, zb;
    LL x;
    void add_h(int w, int wa, int wb) {
        if(za <= wa && wb <= zb) {
            tr[w] += x;
            return;
        }
        int sr = (wa+wb)/2;
        if(za <= sr) add_h(2*w, wa, sr);
        if(zb > sr) add_h(2*w + 1, sr + 1, wb);
    }

    void add(LL y, int a, int b) {
        x = y; za = a; zb = b;
        add_h(1, 0, BASE-1);
    }

    LL get(int a) {
        LL suma = 0;
        for(int w = BASE+a; w > 0; w /= 2) suma += tr[w];
        return suma;
    }

    int get_rev(LL z) {
        int a = -1, b = n;
        while(a+1 < b) {
            int sr = (a+b)/2;
            if(get(sr) <= z) a = sr;
            else b = sr;
        }
        if(a >= 0 && get(a) == )
    }
};

Tree t;

void dopisz(int id, int l) {
    for(int i=0; i<n; i++) cout << t.get(i) << ' ';
    cout << endl;
    if(id < 0) {
        for(int i=0; i<len; i++) {
            LL pos = t.get(i);
            if(pos >= n) break;
            out_str[pos] = str[i];
        }

        for(int i=0; i<n; i++) cout << ((out_str[i] == 0) ? ' ' : out_str[i]);
    cout << '|' << endl;

        return;
    }

    int a = dopiski[id].first, b = dopiski[id].second;
    int ld = max(0, min(b - a + 1, l - 1 - b));
    a = b - ld + 1;

    //int b2 = t.get(b);

    t.add(ld, b+1, n-1);
    dopisz(id - 1, l - ld);
    t.add(-ld, b+1, n-1);

    for(LL i=0; i<ld; i++) {
        LL pos = t.get(b + 1 + i);
        if(pos >= l) break;
        LL pos2 = t.get(b - i);
        out_str[pos] = out_str[pos2];
    }

    for(int i=0; i<n; i++) cout << ((out_str[i] == 0) ? ' ' : out_str[i]);
    cout << '|' << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    REP(i, 2*BASE) tr[i] = 0;

    cin >> str;
    len = str.size();
    cin >> m >> n;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dopiski[i] = {a, b};
    }
    REP(i, n) tr[i+BASE] = i;
    REP(i, n) out_str[i] = 0;

    dopisz(m-1, n);

    while(out_str[n-1] == 0) n--;
    REP(i, n) cout << out_str[i];
    cout << '\n';
}
