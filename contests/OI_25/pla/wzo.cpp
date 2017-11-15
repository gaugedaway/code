#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, s, n) for(int i=(s); i<=(n); i++)
#define FORD(i, s, n) for(int i=(s); i>=(n); i--)
#define DEBUG 1
#define D if(DEBUG)
using namespace std;
typedef long long LL;

const int MN = 500*1000, MD = 1000*1000;

int da[MN], db[MN], n;

void count_sort(vector<int>& v, function<int(int)> fun = [](int a){ return a; }) {
    int n = v.size();
    auto cmp = [&](int a, int b){
        if(fun(a) == fun(b)) return a < b;
        return fun(a) < fun(b);
    };
    int min_el = fun(*min_element(v.begin(), v.end(), cmp));
    int max_el = fun(*max_element(v.begin(), v.end(), cmp));
    vector<int> c(max_el - min_el + 1, 0);
    vector<int> v2(n);
    for(int x: v) c[fun(x) - min_el]++;
    int prev = 0;
    for(int& cnt: c) {
        int temp = cnt;
        cnt = prev;
        prev += temp;
    }
    for(int x: v) v2[c[fun(x) - min_el]++] = x;
    copy(v2.begin(), v2.end(), v.begin());
}

void count_sort_test() {
    cout << "TESTING COUNT SORT..." << endl;
    int len = 1000*1000;
    vector<int> v(len), v2(len);
    REP(i, len) v[i] = v2[i] = i;
    random_shuffle(v.begin(), v.end());
    count_sort(v);
    cout << "Zwykle sortowanie: ";
    if(equal(v.begin(), v.end(), v2.begin())) {
        cout << "OK" << endl;
    }
    else {
        cout << "Nie OK" << endl;
    }

    reverse(v2.begin(), v2.end());
    random_shuffle(v.begin(), v.end());
    count_sort(v, [](int a){ return 1000*1000 - a - 1; });
    cout << "Sortowanie z funkcja: ";
    if(equal(v.begin(), v.end(), v2.begin())) {
        cout << "OK" << endl;
    }
    else {
        cout << "Nie OK" << endl;
    }
}

bool konstruuj(int d, vector<pair<int, int>>& odl, vector<tuple<int, int, int>>& ret) {
    int n = odl.size();
    ret.resize(0);
    ret.reserve(n-1);
    odl[0].first = 0; odl[0].second = d;
    odl[n-1].first = d; odl[n-1].second = 0;

    for(auto& p: odl) if((p.first + p.second - d)%2 == 1) return false;
    #define DIST(i) ((odl[i].first + odl[i].second - d)/2)
    #define DISTA(i) (odl[i].first - DIST(i))

    vector<int> v(n);
    REP(i, n) v[i] = i;
    count_sort(v, [&](int a){ return DISTA(a); });

    int b = 0, e = 0;
    int last = -1, curr;
    while(b < n) {
        int db = DISTA(v[b]);
        while(e < n-1 && DISTA(v[e+1]) == db) e++;
        // teraz b i e wyznaczaja przedzial o tych samych wartosciach

        // znajdz wierzcholek na linii
        curr = -1;
        for(int i=b; i<=e; i++) if(DIST(v[i]) == 0) {
            if(db != d - odl[v[i]].second + DIST(v[i])) return false;
            if(curr != -1) return false;
            curr = v[i];
        }
        if(curr == -1) return false;

        // podlacz go do poprzedniego
        if(last != -1) ret.push_back(make_tuple(last, curr, db - DISTA(last)));

        for(int i=b; i<=e; i++) if(DIST(v[i]) > 0) {
            ret.push_back(make_tuple(curr, v[i], DIST(v[i])));
        }

        last = curr;
        b = e = e+1;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n <= 2) {
        cout << "TAK\n1 2 1\n";
        return 0;
    }

    vector<pair<int, int>> odl(n);
    for(int i=1; i<n-1; i++) {
        cin >> odl[i].first;
    }
    for(int i=1; i<n-1; i++) {
        cin >> odl[i].second;
    }

    int min_idx = distance(odl.begin(), min_element(odl.begin()+1, odl.end()-1));

    int d1 = odl[min_idx].first + odl[min_idx].second;
    int d2 = abs(odl[min_idx].first - odl[min_idx].second);

    vector<tuple<int, int, int>> ret;
    bool ok = konstruuj(d1, odl, ret);
    if(!ok) {
        ok = konstruuj(d2, odl, ret);
        if(!ok) {
            cout << "NIE\n";
            return 0;
        }
    }

    cout << "TAK\n";
    int a, b, w;
    for(auto& t: ret) {
        tie(a, b, w) = t;
        cout << a+1 << ' ' << b+1 << ' ' << w << '\n';
    }
}
