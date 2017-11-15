#include <bits/stdc++.h>
#include "game.h"
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int g_row_a, g_row_b, g_col_a, g_col_b;
int g_num_rows, g_num_cols;
ll g_val;

inline ll gcc(ll a, ll b) {
    while(b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

template <class T>
inline T* & E(T* & p) {
    if(p == nullptr) p = new T;
    return p;
}

struct TreeCol {
    TreeCol *left = nullptr, *right = nullptr;
    ll val = 0;

    ~TreeCol() {
	delete left;
	delete right;
    }

    void rset(int wa, int wb) {
	if(g_col_a < wa || wb < g_col_a) return;
	if(wa == wb) {
	    val = g_val;
	    return;
	}
	int sr = (wa + wb) / 2;
	E(left)->rset(wa, sr);
	E(right)->rset(sr + 1, wb);
	val = gcc(E(left)->val, E(right)->val);
    }

    ll rget(int wa, int wb) {
	if(g_col_b < wa || wb < g_col_a) return 0;
	if(g_col_a <= wa && wb <= g_col_b) return val;
	int sr = (wa + wb) / 2;
	return gcc(E(left)->rget(wa, sr),
		   E(right)->rget(sr + 1, wb));
    }
};

struct TreeRow {
    TreeRow *left = nullptr, *right = nullptr;
    TreeCol* tc;

    TreeRow() : tc(new TreeCol) {}
    ~TreeRow() {
	delete left;
	delete right;
    }

    void rset(int wa, int wb) {
	if(g_row_a < wa || wb < g_row_a) return;

        g_col_b = g_col_a;
        ll prev_val = tc->rget(0, g_num_cols - 1);
        ll tmp = g_val;
        g_val = gcc(g_val, prev_val);
        tc->rset(0, g_num_cols - 1);
        g_val = tmp;

	if(wa == wb) return;
	int sr = (wa + wb) / 2;
	E(left)->rset(wa, sr);
	E(right)->rset(sr + 1, wb);
    }

    ll rget(int wa, int wb) {
	if(g_row_b < wa || wb < g_row_a) return 0;
	if(g_row_a <= wa && wb <= g_row_b) {
            return tc->rget(0, g_num_cols - 1);
        }
	int sr = (wa + wb) / 2;
	return gcc(E(left)->rget(wa, sr),
		   E(right)->rget(sr + 1, wb));
    }

    void set(int p_row, int p_col, ll x) {
        g_row_a = p_row;
        g_col_a = p_col;
        g_val = x;
        rset(0, g_num_rows - 1);
    }

    ll get(int row_a, int row_b, int col_a, int col_b) {
        g_row_a = row_a;
        g_row_b = row_b;
        g_col_a = col_a;
        g_col_b = col_b;
        return rget(0, g_num_rows - 1);
    }
};

TreeRow tr;

void init(int r, int c) {
    g_num_rows = r;
    g_num_cols = c;
}

void update(int p, int q, ll k) {
    tr.set(p, q, k);
}

ll calculate(int p, int q, int u, int v) {
    return tr.get(p, u, q, v);
}
