#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
#define DEBUG 0
#define D if(DEBUG)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

inline int sgn(int a) {
    if(a > 0) return 1;
    else if(a < 0) return -1;
    else return 0;
}

inline int det(PII a, PII b) {
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
        if(det(v[a], v[b]) == 0) return a < b;
        else return det(v[a], v[b]) < 0;
    };
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    vector<PII> v3(n);
    int j = 0;
    for(int x: v1) v3[j++] = v[x];
    for(int x: v2) v3[j++] = v[x];
    copy(v3.begin(), v3.end(), v.begin());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<PII> wektory(n);
    REP(i, n) cin >> wektory[i].first >> wektory[i].second;

    angle_sort(wektory);

    LL najw = 0;
    REP(i, n) {
        PLL suma = {0, 0};
        REP(j, n) {
            suma.first += wektory[(i+j)%n].first;
            suma.second += wektory[(i+j)%n].second;
            najw = max(najw, len(suma));
        }
    }

    cout << najw << '\n';
}
