#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
#define DEBUG 0
#define D if(DEBUG)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int MX = 97103;

inline LL sgn(LL a) {
    if(a > 0) return 1;
    else if(a < 0) return -1;
    else return 0;
}

inline LL det(PLL a, PLL b) {
    return a.first * b.second - a.second * b.first;
}

inline LL len(PLL a) {
    return a.first * a.first + a.second * a.second;
}

void angle_sort(vector<PII>& v) {
    int n = v.size();
    vector<int> v1, v2;
    PII piv = {1, 0};
    REP(i, n) {
        if(det(v[i], piv) == 0) {
            if(sgn(v[i].first) == sgn(piv.first)) v1.push_back(i);
            else v2.push_back(i);
        }
        else if(det(v[i], piv) > 0) v1.push_back(i);
        else v2.push_back(i);
    }

    auto cmp = [&](int a, int b) {
        if(det(v[a], v[b]) == 0) {
            if(v[a].first == v[b].first) {
                if(v[a].second == v[a].second) return a < b;
                return v[a].second < v[b].second;
            }
            return v[a].first < v[b].first;
        }
        return det(v[a], v[b]) < 0;
    };
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    vector<PII> v3(n);
    int j = 0;
    for(int x: v1) v3[j++] = v[x];
    for(int x: v2) v3[j++] = v[x];
    copy(v3.begin(), v3.end(), v.begin());
}

inline PII generuj_proste(int i) {
    int faza = i/(2*MX + 1);
    int j = i%(2*MX + 1);

    if(faza == 0) return {MX, MX - j};
    if(faza == 1) return {MX - j, -MX};
    if(faza == 2) return {-MX, j - MX};
    else return {j - MX, MX};

    /* for(int i=MX; i>=-MX; i--) v.push_back({MX, i});
    for(int i=MX; i>=-MX; i--) v.push_back({i, -MX});
    for(int i=-MX; i<=MX; i++) v.push_back({-MX, i});
    for(int i=-MX; i<=MX; i++) v.push_back({i, MX}); */
}

void operator+=(PLL & a, PII & b) {
    a.first += b.first;
    a.second += b.second;
}

void operator-=(PLL & a, PII & b) {
    a.first -= b.first;
    a.second -= b.second;
}

inline PII neg(PII & a) {
    return {-a.first, -a.second};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<PII> we;
    we.reserve(n+2);
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        if(x != 0 || y != 0) we.push_back({x, y});
    }
    n = we.size();
    if(n == 0) {
        cout << "0\n";
        return 0;
    }
    if(n == 1) {
        cout << len(we[0]) << '\n';
        return 0;
    }

    PII p0 = generuj_proste(0);
    PII p0m = neg(p0);

    PLL suma = {0, 0};
    int w = 0, poza = 0;
    for(PII v: we) {
        if(det(p0, v) >= 0) {
            suma += v;
            w++;
        }
        else poza++;
    }

    we.push_back(p0);
    we.push_back(p0m);
    angle_sort(we);

    int b1 = 0, b2 = 0;
    REP(i, n+2) {
        if(we[i] == p0m) b1 = (i+1)%(n+2);
        if(we[i] == p0) b2 = (i+1)%(n+2);
    }

    LL najw = 0;
    bool skip = false;
    REP(i, 4*(2*MX + 1)) {
        PII p = generuj_proste(i);
        while((skip = (we[b1] == p0 || we[b1] == p0m)) || (w > 0 && det(p, we[b1]) < 0)) {
            if(!skip) {
                suma -= we[b1];
                w--; poza++;
            }
            b1 = (b1+1)%(n+2);
            skip = false;
        }
        while((skip = (we[b2] == p0 || we[b2] == p0m)) || (poza > 0 && det(p, we[b2]) >= 0)) {
            if(!skip) {
                suma += we[b2];
                poza--; w++;
            }
            b2 = (b2+1)%(n+2);
            skip = false;
        }
        najw = max(najw, len(suma));
    }

    cout << najw << '\n';
}
