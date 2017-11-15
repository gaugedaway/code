#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

template <typename T>
struct SumTree {
    vector<T> v;
    int n;

    SumTree(int n_) : n(n_) {
        v.resize(2*n);
    }

    int za, zb;
    T val;

    void set_rec(int w, int wa, int wb) {
        if(za < wa || wb < za) return;
        if(wb == wa) {
            v[w] = val;
            return;
        }
        int sr = (wa + wb)/2;
        set_rec(2*w, wa, sr);
        set_rec(2*w + 1, sr + 1, wb);
        v[w] = v[2*w] + v[2*w + 1];
    }

    void set(T x, int pos) {
        za = pos; val = x;
        set_rec(1, 0, n-1);
    }

    T get_sum_rec(int w, int wa, int wb) {
        if(zb < wa || wb < za) return 0;
        if(za <= wa && wb <= zb) return v[w];
        int sr = (wa + wb)/2;
        return get_sum_rec(2*w, wa, sr) +
               get_sum_rec(2*w + 1, sr + 1, wb);
    }

    T get_sum(int a, int b) {
        za = a; zb = b;
        return get_sum_rec(1, 0, n-1);
    }
};

void print_vec(vector<int>& v) {
    for(int x: v) cout << x << ' ';
    cout << endl;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    vector<int> v(10);
    SumTree<int> tr(15);
    while(true) {
        cout << "Operacja: ";
        char c;
        cin >> c;
        if(c == 'q') { return 0; }
        else if(c == 's') {
            int pos, x;
            cout << "Pozycja: ";
            cin >> pos;
            cout << "Wartosc: ";
            cin >> x;
            tr.set(x, pos);
            v[pos] = x;
        }
        else if(c == 'g') {
            int a, b;
            cout << "Przedzial: ";
            cin >> a >> b;
            cout << "Suma = " << tr.get_sum(a, b);
        }
        print_vec(v);
    }
}
