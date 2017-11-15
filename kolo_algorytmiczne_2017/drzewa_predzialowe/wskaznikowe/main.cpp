#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

ll g_val;
int g_za, g_zb;
int g_base;

struct Tree {
    Tree *left, *right;
    ll val = 0;

    Tree() : left(nullptr), right(nullptr) {}
    ~Tree() {
        delete left;
        delete right;
    }

    inline Tree* E(Tree* & ptr) {
        if(ptr == nullptr) ptr = new Tree;
        return ptr;
    }
    
    void set_rec(int wa, int wb) {
        if(g_za < wa || wb < g_za) return;
        if(wa == wb) {
            val = g_val;
            return;
        }
        int sr = (wa + wb) / 2;
        E(left)->set_rec(wa, sr);
        E(right)->set_rec(sr + 1, wb);
        val = E(left)->val + E(right)->val;
    }

    void set(ll x, int pos) {
        g_val = x; g_za = pos;
        set_rec(0, g_base - 1);
    }

    ll get_rec(int wa, int wb) {
        if(g_zb < wa || wb < g_za) return 0;
        if(g_za <= wa && wb <= g_zb) return val;
        int sr = (wa + wb) / 2;
        return E(left)->get_rec(wa, sr) +
               E(right)->get_rec(sr + 1, wb);
    }

    ll get(int a, int b) {
        g_za = a; g_zb = b;
        return get_rec(0, g_base - 1);
    }
};

Tree* create_tree(int n) {
    g_base = n;
    return new Tree;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Tree* tr = create_tree(1000000000);
    tr->set(100, 1000000);
    tr->set(21, 100000000);
    cout << tr->get(500, 200000000) << endl;
}
