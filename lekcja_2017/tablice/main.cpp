#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;
#define DEBUG 0
#define D if(DEBUG)

const int HMOD = 1000007, HMUL = 1000000;


vector<int> count_sort(vector<int>& v) {
    int n = v.size();
    int mi = *min_element(v.begin(), v.end());
    int m = *max_element(v.begin(), v.end()) - mi + 1;
    vector<int> c(m, 0), v2(n);
    for(int i=0; i<n; i++) c[v[i] - mi]++;
    int last = c[0];
    c[0] = 0;
    for(int i=1; i<m; i++) {
        int cp = c[i];
        c[i] = last + c[i-1];
        last = cp;
    }
    for(int i=0; i<n; i++) {
        v2[c[v[i] - mi]] = v[i];
        c[v[i] - mi]++;
    }
    return v2;
}

int hash_(vector<int>& v) {
    int h = 0;
    for(int x: v) h = (LL(h)*LL(HMUL) + x)%HMOD;
    return h;
}

void read(vector<vector<int>>& v, int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
}

bool check_rows(vector<vector<int>>& t1, vector<vector<int>>& t2) {
    int n = t1.size(), m = t1[0].size();
    vector<pair<int, int>> row_h1(n), row_h2(n);
    vector<int> tmp(m);
    for(int i=0; i<n; i++) {
        tmp = count_sort(t1[i]);
        row_h1[i] = {hash_(tmp), i};
        tmp = count_sort(t2[i]);
        row_h2[i] = {hash_(tmp), i};
    }
    sort(row_h1.begin(), row_h1.end());
    sort(row_h2.begin(), row_h2.end());
    for(int i=0; i<n; i++) {
        if(row_h1[i].first != row_h2[i].first) return false;
        else {
            int r1 = row_h1[i].second;
            int r2 = row_h2[i].second;
            for(int j=0; j<m; j++) if(t1[r1][j] != t2[r2][j]) return false;
        }
    }
    return true;
}

void transpose(vector<vector<int>>& t) {
    int n = t.size(), m = t[0].size();
    vector<vector<int>> tmp(m);
    for(auto& row: tmp) row.resize(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            tmp[j][i] = t[i][j];
    copy(tmp.begin(), tmp.end(), t.begin());
}

void print_tab(vector<vector<int>>& t) {
    for(auto& row: t) {
        for(int x: row) {
            cout << x << ' ';
        }
        cout << endl;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> t1(n), t2(n);
    for(auto& row: t1) row.resize(m);
    for(auto& row: t2) row.resize(m);

    REP(i, n) REP(j, m) {
        cin >> t1[i][j];
    }
    REP(i, n) REP(j, m) {
        cin >> t2[i][j];
    }

    if(!check_rows(t1, t2)) {
        cout << "NIE\n";
        return;
    }

    transpose(t1);
    transpose(t2);

    if(!check_rows(t1, t2)) {
        cout << "NIE\n";
        return;
    }

    cout << "TAK\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();
}
