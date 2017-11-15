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

inline LL det(PLL a, PLL b) {
    return a.first * b.second - a.second * b.first;
}

inline LL len(PLL a) {
    return a.first * a.first + a.second * a.second;
}

void angle_sort(vector<PLL>& v) {
    vector<PLL> v1, v2;
    PLL piv = {1, 0};
    for(PLL x: v) {
        if(det(x, piv) == 0) {
            if(sgn(x.first) == sgn(piv.first)) v1.push_back(x);
            else v2.push_back(x);
        }
        else if(det(x, piv) > 0) v1.push_back(x);
        else v2.push_back(x);
    }

    auto cmp = [=](PLL a, PLL b) {
        if(det(a, b) == 0) {
            if(a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        }
        else return det(a, b) < 0;
    };
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    int j = 0;
    for(PLL x: v1) v[j++] = x;
    for(PLL x: v2) v[j++] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<PLL> wektory(n);
    REP(i, n) cin >> wektory[i].first >> wektory[i].second;

    angle_sort(wektory);

    PLL suma = wektory[0];
    LL najw = len(suma);
    int b = 0, next = 1;
    for(; next < 2*n; next++) {
        PLL nowa_suma = {suma.first + wektory[next%n].first, suma.second + wektory[next%n].second};
        while(b < next && (next - b + 1 > n || len(nowa_suma) < len(suma))) {
            suma.first -= wektory[b%n].first;
            suma.second -= wektory[b%n].second;
            nowa_suma.first -= wektory[b%n].first;
            nowa_suma.second -= wektory[b%n].second;
            b++;
            if(b < next && next - b <= n) {
                D if(len(suma) > najw) {
                    cout << "Nowa suma: " << len(suma) << endl;
                    cout << "b = " << b << ", next = " << next << endl;
                }
                najw = max(najw, len(suma));
            }
        }
        D if(len(nowa_suma) > najw) {
            cout << "Nowa suma: " << len(nowa_suma) << endl;
            cout << "b = " << b << ", next = " << next << endl;
        }
        najw = max(najw, len(nowa_suma));
        suma = nowa_suma;
    }

    cout << najw << '\n';
}
